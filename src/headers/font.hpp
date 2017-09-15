#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>
#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <shader.hpp>

struct Glyph {
    GLuint textureId;
    GLuint advance;
    glm::ivec2 size;
    glm::ivec2 bearing;
};

class Font {
    FT_UInt pixelWidth;
    FT_UInt pixelHeight;
    std::string name;
    std::map<GLubyte, Glyph> glyphMap;

    Shader shader;
    GLuint vao = 0, vbo = 0;

    void initGlyphMap(const std::string &fontName, FT_UInt pixelWidth, FT_UInt pixelHeight);
    void initVao();

public:

    Font(const std::string &fontName, const std::string &vsPath, const std::string &fsPath,
         FT_UInt pixelWidth = 0, FT_UInt pixelHeight = 48)
            : shader(vsPath, fsPath), pixelWidth(pixelWidth), pixelHeight(pixelHeight), name(fontName) {
        initGlyphMap(fontName, pixelWidth, pixelHeight);
        initVao();
    }

    void renderText(Shader &shader, const std::string &text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
};

void Font::initGlyphMap(const std::string &fontName, FT_UInt pixelWidth, FT_UInt pixelHeight) {

    FT_Library ftLibrary;
    if (FT_Init_FreeType(&ftLibrary)) {
        Log::e("Font::Font", "Failed to init FreeType");
        throw fontName;
    }

    FT_Face face;
    if (FT_New_Face(ftLibrary, fontName.c_str(), 0, &face)) {
        Log::e("Font::Font", boost::format("Failed to load font: %s") % fontName);
        throw fontName;
    }

    FT_Set_Pixel_Sizes(face, pixelWidth, pixelHeight);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    for (GLubyte c = 0; c < 128; c++) {
        if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
            Log::e("Font::Font", boost::format("Failed to load glyph: %c") % c);
            throw fontName;
        }

        GLuint texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows,
                     0, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        Glyph glyph = {
                texture,
                static_cast<GLuint>(face->glyph->advance.x),
                glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top)
        };
        glyphMap.insert(std::pair<GLubyte, Glyph>(c, glyph));
    }

    glBindTexture(GL_TEXTURE_2D, 0);

    FT_Done_Face(face);
    FT_Done_FreeType(ftLibrary);
}

void Font::initVao() {

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, nullptr, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Font::renderText(Shader &shader, const std::string &text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color) {

    shader.bind();
    glUniform3f(glGetUniformLocation(shader.getId(), "textColor"), color.x, color.y, color.z);
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(vao);

    std::string::const_iterator c;
    for (c = text.begin(); c != text.end(); c++) {
        auto g = glyphMap[*c];

        float xpos = x + g.bearing.x * scale;
        float ypos = y - (g.size.y - g.bearing.y) * scale;

        float w = g.size.x * scale;
        float h = g.size.y * scale;

        float vertices[6][4] = {
                { xpos, ypos + h, 0.0, 0.0 },
                { xpos, ypos, 0.0, 1.0 },
                { xpos + w, ypos, 1.0, 1.0 },

                { xpos, ypos + h, 0.0, 0.0 },
                { xpos + w, ypos, 1.0, 1.0 },
                { xpos + w, ypos + h, 1.0, 0.0 }
        };

        glBindTexture(GL_TEXTURE_2D, g.textureId);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        x += (g.advance >> 6) * scale; // bit shift by six to get value in pixels
    }
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}