//
// Created by benjamin on 9/3/17.
//

#ifndef DEMO_TEMPLATE_FILE_LOADING_HPP
#define DEMO_TEMPLATE_FILE_LOADING_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

std::string loadFile(const std::string &filename) {
    std::string content;
    std::ifstream file;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        file.open(filename);

        std::stringstream ss;
        ss << file.rdbuf();
        file.close();

        content = ss.str();
    } catch (std::ifstream::failure &e) {
        std::cerr << "Error loading file '" << filename << "'" << std::endl;
    }

    return content;
}

void loadFile(const std::string &filename, std::string *output) {
    std::ifstream file;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        file.open(filename);

        std::stringstream ss;
        ss << file.rdbuf();
        file.close();

        output->assign(ss.str());
    } catch (std::ifstream::failure &e) {
        std::cerr << "Error loading file '" << filename << "'" << std::endl;
    }
}

#endif //DEMO_TEMPLATE_FILE_LOADING_HPP
