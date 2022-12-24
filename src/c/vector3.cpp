#include "vector3.h"

#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>

vector3 vector3::operator+(const vector3& other) const {
        return vector3(x + other.x, y + other.y, z + other.z);
}

// Overloading the - operator for vector subtraction
vector3 vector3::operator-(const vector3& other) const {
    return vector3(x - other.x, y - other.y, z - other.z);
}

// Overloading the * operator for dot product
float vector3::operator*(const vector3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

// Overloading the * operator for scalar multiplication
vector3 vector3::operator*(float scalar) const {
    return vector3(x * scalar, y * scalar, z * scalar);
}

vector3 vector3::cross(const vector3& other) const {
    return vector3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

vector3 vector3::from_string(std::string string) {
    // format is (x, y, z)
    double x = 0;
    double y = 0;
    double z = 0;
    int ci = 0;
    int li = 1;
    
    for (size_t i=string.size()-1;i>0;--i) {
        if(string[i] == ' ' || string[i] == '(' || string[i] == ')') continue;
        std::string str = "";
        str.push_back(string[i]);
        std::cout << str << '\n';
        if(ci == 0) z += std::stof(str); 
        if(string[i] == ',') ci++;
        else li *= 10;
    }

    // Return a vector3 object with the extracted values
    return vector3(x, y, z);
}