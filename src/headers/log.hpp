//
// Created by benjamin on 9/14/17.
//

#ifndef DEMO_TEMPLATE_LOG_HPP
#define DEMO_TEMPLATE_LOG_HPP

#include <string>
#include <ostream>
#include <iostream>
#include <boost/format.hpp>

enum LogLevel { VERBOSE, DEBUG, ERROR };

class Log {
    static LogLevel _logLevel;
    static void log(std::ostream &out, const std::string &tag, const std::string &msg);

public:

    static void v(const std::string &tag, const std::string &msg) {
        if (_logLevel >= LogLevel::VERBOSE) log(std::cout, tag, msg);
    }

    static void v(const std::string &tag, const boost::format &msgFormat) {
        v(tag, msgFormat.str());
    }

    static void d(const std::string &tag, const std::string &msg) {
        if (_logLevel >= LogLevel::DEBUG) log(std::cout, tag, msg);
    }

    static void d(const std::string &tag, const boost::format &msgFormat) {
        d(tag, msgFormat.str());
    }

    static void e(const std::string &tag, const std::string &msg) {
        if (_logLevel >= LogLevel::ERROR) log(std::cerr, tag, msg);
    }

    static void e(const std::string &tag, const boost::format &msgFormat) {
        e(tag, msgFormat.str());
    }

    static void setLogLevel(LogLevel logLevel) {
        _logLevel = logLevel;
    }
};

#endif //DEMO_TEMPLATE_LOG_HPP
