#include "string_utils.h"

#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> string_utils::split(std::string string) {
    std::stringstream ssplit(string);
    std::string segment;
    std::vector<std::string> split;
    while(std::getline(ssplit, segment, ' ')) split.push_back(segment);
    return split;
}

std::vector<std::string> string_utils::split_ignore_parenthesis(std::string string) {
    std::vector<std::string> result;
    std::string current;
    std::size_t i = 0;

    // Iterate through each character in the string
    while (i < string.size()) {
        char c = string[i];
        if (c == '(') {
            // If we encounter an opening parenthesis, start a new segment and ignore spaces until the closing parenthesis
            current.clear();
            current += c;
            while (c != ')') {
                c = string[++i];
                current += c;
            }
        } else if (c == ' ') {
            // If we encounter a space, end the current segment and start a new one
            if (!current.empty()) {
                result.push_back(current);
                current.clear();
            }
        } else current += c; // Otherwise, just add the character to the current segment
        
        ++i;
    }

    // Push the final segment onto the result vector
    if (!current.empty()) result.push_back(current);

    return result;
}

bool string_utils::starts_with(std::string string, std::string prefix) {
    if(prefix.size() > string.size()) return false;
    for(int i=0;i<prefix.size();i++) if(string.at(i) != prefix.at(i)) return false; 
    return true;
}
