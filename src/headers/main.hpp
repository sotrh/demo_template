//
// Created by benjamin on 8/2/17.
//

#ifndef DEMO_TEMPLATE_MAIN_HPP
#define DEMO_TEMPLATE_MAIN_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>

#include <files.hpp>
#include <shader.hpp>
#include <texture.hpp>

void errorCallback(int error, const char *description);

void keyCallback(GLFWwindow *window, int key, int scanCode, int action, int mods);

#endif //DEMO_TEMPLATE_MAIN_HPP
