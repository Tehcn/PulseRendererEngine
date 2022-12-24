#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

#include "vector3.h"
#include "string_utils.h"
#include "binary_tree.h"

void clear(void) {
    system("clear");
}

float add(float a, float b) {
    return a + b;
}

int main(void) {
    system("clear");
    std::cout << " Engine Ready!\n";
    std::string input;
    while(true) {
        std::cout << " PulseRendererEngine$ ";
        std::getline(std::cin, input);
        std::vector<std::string> split = string_utils::split_ignore_parenthesis(input);
        std::vector<std::string> args = split;
        std::string cmd = split[0];
        if(args.size() > 1) args.erase(args.begin());
        if(input == "exit") break;
        if(input == "clear") clear();
        if(cmd == "add" && args.size() == 2) std::cout << add(std::stof(args[0]), std::stof(args[1])) << "\n";
        // if(cmd == "vec" && args.size() == 1) std::cout << vector3::from_string(args[0]) << "\n";
        if(cmd == "test") {
            binary_tree<std::string>* tree = new binary_tree<std::string>();
            node<std::string>* l1 = new node<std::string>("l1", tree->getApexNode());
            node<std::string>* r1 = new node<std::string>("r1", tree->getApexNode());
            node<std::string>* l1l2 = new node<std::string>("l1l2", l1);
            node<std::string>* l1r2 = new node<std::string>("1l2r", r1);
        }
    }
    return 0;
}
