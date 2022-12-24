#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include <vector>

namespace string_utils {
    std::vector<std::string> split(std::string string);
    std::vector<std::string> split_ignore_parenthesis(std::string string);
    bool starts_with(std::string string, std::string prefix);
}

#endif