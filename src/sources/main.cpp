#include <main.hpp>

bool useSolidColorShader = true;

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

    // create a triangle

    float vertices[] = {
            // positions         // colors
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   // bottom right
            -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,   // bottom left
            0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f    // top
    };

    uint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    uint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) nullptr);
    glEnableVertexAttribArray(0);

    // color attribute

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // create the solidColorShader

    Shader solidColorShader("assets/shaders/position.vert", "assets/shaders/color.frag");
    Shader vertexColorShader("assets/shaders/vertex_color.vert", "assets/shaders/vertex_color.frag");

    while (glfwWindowShouldClose(window) == GLFW_FALSE) {
        glClear(GL_COLOR_BUFFER_BIT);

        if (useSolidColorShader) {
            glUseProgram(solidColorShader.id);
        } else {
            glUseProgram(vertexColorShader.id);
        }

        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

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
        useSolidColorShader = !useSolidColorShader;
    }
}