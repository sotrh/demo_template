#include <main.hpp>

#define MAX_SHADERS 5
unsigned int currentShader = 0;

int main() {
    GLFWwindow *window;

    glfwSetErrorCallback(errorCallback);

    if (glfwInit() == GLFW_FALSE) {
        return -1;
    }

    window = glfwCreateWindow(800, 600, "Demo Template", nullptr, nullptr);
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
            0, 1, 3, // 1st triangle
            1, 2, 3  // 2nd triangle
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

    while (glfwWindowShouldClose(window) == GLFW_FALSE) {
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
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

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