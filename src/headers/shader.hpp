//
// Created by benjamin on 9/4/17.
//

#ifndef DEMO_TEMPLATE_SHADER_HPP
#define DEMO_TEMPLATE_SHADER_HPP

#include <glad/glad.h>
#include <files.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:
    unsigned int id;

    Shader(const std::string &vertexPath, const std::string &fragmentPath) {
        std::string vsString;
        std::string fsString;

        loadFile(vertexPath, &vsString);
        loadFile(fragmentPath, &fsString);

        int success;
        char infoLog[1024];

        loadFile("assets/shaders/position.vert", &vsString);
        auto vertexShaderSource = vsString.c_str();
        auto vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
        glCompileShader(vertexShader);
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

        if (!success) {
            glGetShaderInfoLog(vertexShader, 1024, nullptr, infoLog);
            std::cerr << "Unable to compile vertexShader:" << std::endl << infoLog << std::endl;
        }

        loadFile("assets/shaders/color.frag", &fsString);
        auto fragmentShaderSource = fsString.c_str();
        auto fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

        if (!success) {
            glGetShaderInfoLog(vertexShader, 1024, nullptr, infoLog);
            std::cerr << "Unable to compile fragmentShader:" << std::endl << infoLog << std::endl;
        }

        id = glCreateProgram();
        glAttachShader(id, vertexShader);
        glAttachShader(id, fragmentShader);
        glLinkProgram(id);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }
};

#endif //DEMO_TEMPLATE_SHADER_HPP
