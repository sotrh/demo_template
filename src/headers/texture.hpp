//
// Created by benjamin on 9/12/17.
//

#ifndef DEMO_TEMPLATE_TEXTURE_HPP
#define DEMO_TEMPLATE_TEXTURE_HPP

#include <glad/glad.h>
#include <sstream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

class Texture {
public:
    unsigned int id = 0;
    int width = 0, height = 0, nrChannels = 0;

    Texture(const char * filename, GLint internalFormat, GLenum desiredFormat, bool flipVerticallyOnLoad = false) {

        stbi_set_flip_vertically_on_load(flipVerticallyOnLoad);
        unsigned char * data = stbi_load(filename, &width, &height, &nrChannels, 0);

        if (data != nullptr) {
            glGenTextures(1, &id);
            glBindTexture(GL_TEXTURE_2D, id);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, desiredFormat, GL_UNSIGNED_BYTE, data);

            stbi_image_free(data);

        } else {
            std::stringstream ss;
            ss << "Unable to load texture: '" << filename << "'";
            throw(ss.str());
        }
    }

    void bind(unsigned int textureIndex = 0) {
        glActiveTexture(GL_TEXTURE0 + textureIndex);
        glBindTexture(GL_TEXTURE_2D, id);
    }
};

#endif //DEMO_TEMPLATE_TEXTURE_HPP
