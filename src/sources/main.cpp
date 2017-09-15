#include <main.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define WIDTH 800
#define HEIGHT 600

#define MAX_SHADERS 5
unsigned int currentShader = 0;

int main() {
    GLFWwindow *window;

    glfwSetErrorCallback(errorCallback);

    if (glfwInit() == GLFW_FALSE) {
        return -1;
    }

    window = glfwCreateWindow(WIDTH, HEIGHT, "Demo Template", nullptr, nullptr);
    if (window == nullptr) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glfwSetKeyCallback(window, keyCallback);

    if (gladLoadGL() == 0) {
        std::cout << "GLAD failed to load" << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    // create a quad

    float vertices[] = {
            // positions          // colors           // texture coords
             0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
             0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
            -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
            -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left
    };

    unsigned int indices[] = {
            0, 3, 1, // 1st triangle
            1, 3, 2  // 2nd triangle
    };

    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) nullptr);
    glEnableVertexAttribArray(0);

    // color attribute

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // texture attribute

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // font and text

    Shader textShader("assets/shaders/text.vert", "assets/shaders/text.frag");
    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(WIDTH), 0.0f, static_cast<GLfloat>(HEIGHT));
    textShader.bind();
    glUniformMatrix4fv(glGetUniformLocation(textShader.getId(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));

    Font font("assets/fonts/arial.ttf", "assets/shaders/text.vert", "assets/shaders/text.frag");

    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // texture

    Texture awesomeFaceTexture("assets/images/awesomeface.png", GL_RGBA, GL_RGBA, true);
    Texture containerTexture("assets/images/container.jpg", GL_RGB, GL_RGB);

    // create the solidColorShader

    Shader solidColorShader("assets/shaders/position.vert", "assets/shaders/color.frag");
    Shader vertexColorShader("assets/shaders/vertex_color.vert", "assets/shaders/vertex_color.frag");
    Shader textureShader("assets/shaders/texture.vert", "assets/shaders/texture.frag");
    Shader textureColorShader("assets/shaders/texture.vert", "assets/shaders/texture-color.frag");
    Shader texture2Shader("assets/shaders/texture.vert", "assets/shaders/texture2.frag");

    texture2Shader.bind();
    texture2Shader.setInt("texture1", 0);
    texture2Shader.setInt("texture2", 1);

    double lastTime = glfwGetTime();
    int frames = 0;
    std::string frameRate = "N/A ms/frame";
    std::string inverseFrameRate = "N/A fps";

    while (glfwWindowShouldClose(window) == GLFW_FALSE) {
        double currentTime = glfwGetTime();
        frames++;
        if (currentTime - lastTime >= 1.0) {
            std::stringstream ss;
            ss << 1000.0 / double(frames) << " ms/frame";
            frameRate.assign(ss.str());

            ss.str("");
            ss << frames << " fps";
            inverseFrameRate.assign(ss.str());

            frames = 0;
            lastTime += 1.0;
        }

        glClear(GL_COLOR_BUFFER_BIT);

        if (currentShader == 0) {
            solidColorShader.bind();
        } else if (currentShader == 1) {
            vertexColorShader.bind();
        } else if (currentShader > 1 && currentShader < MAX_SHADERS) {
            containerTexture.bind();

            if (currentShader == 2) {
                textureShader.bind();
            } else if (currentShader == 3) {
                textureColorShader.bind();
            } else if (currentShader == 4) {
                awesomeFaceTexture.bind(1);
                texture2Shader.bind();
            }
        }

        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        font.renderText(textShader, frameRate, 25.0f, HEIGHT - 25.0f, 0.5f, glm::vec3(1, 1, 1));
        font.renderText(textShader, inverseFrameRate, 25.0f, HEIGHT - 50.0f, 0.5f, glm::vec3(1, 1, 1));
        font.renderText(textShader, "This is sample text", 25.0f, 25.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));
        font.renderText(textShader, "(C) LearnOpenGL.com", 540.0f, 570.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

void errorCallback(int error, const char *description) {
    std::cout << error << ": " << description << std::endl;
}

void keyCallback(GLFWwindow *window, int key, int scanCode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    else if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        currentShader++;
        if (currentShader == MAX_SHADERS) currentShader = 0;
    }
}