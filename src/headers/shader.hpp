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
    unsigned int id;
public:

    Shader(const std::string &vertexPath, const std::string &fragmentPath) {
        std::string vsString;
        std::string fsString;

        loadFile(vertexPath, &vsString);
        loadFile(fragmentPath, &fsString);

        int success;
        char infoLog[1024];

        auto vertexShaderSource = vsString.c_str();
        auto vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
        glCompileShader(vertexShader);
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

        if (!success) {
            glGetShaderInfoLog(vertexShader, 1024, nullptr, infoLog);
            Log::e("Shader::Shader", boost::format("Unable to compile vertex shader:\n%s") % infoLog);
        }

        auto fragmentShaderSource = fsString.c_str();
        auto fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

        if (!success) {
            glGetShaderInfoLog(vertexShader, 1024, nullptr, infoLog);
            Log::e("Shader::Shader", boost::format("Unable to compile fragment shader:\n%s") % infoLog);
        }

        id = glCreateProgram();
        glAttachShader(id, vertexShader);
        glAttachShader(id, fragmentShader);
        glLinkProgram(id);

        glGetProgramiv(id, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(id, 1024, nullptr, infoLog);
            Log::e("Shader::Shader", boost::format("Unable to link shader program:\n%s") % infoLog);
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    void bind() {
        glUseProgram(id);
    }

    void setInt(const char * uniformName, const int i) {
        setInt(glGetUniformLocation(id, uniformName), i);
    }

    void setInt(const int location, const int i) {
        glUniform1i(location, i);
    }

    unsigned int getId() {
        return id;
    }
};

#endif //DEMO_TEMPLATE_SHADER_HPP
