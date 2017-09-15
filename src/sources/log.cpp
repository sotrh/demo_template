#include <log.hpp>

LogLevel Log::_logLevel = LogLevel::VERBOSE;

void Log::log(std::ostream &out, const std::string &tag, const std::string &msg) {
    out << tag << ": " << msg;
}