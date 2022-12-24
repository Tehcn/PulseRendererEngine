#ifndef VECTOR3_H
#define VECTOR3_H

#include <string>
#include <iostream>

class vector3 {
public:
    float x, y, z;

    // Default constructor
    vector3() : x(0), y(0), z(0) {}

    // Constructor with three arguments
    vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    // Copy constructor
    vector3(const vector3& other) : x(other.x), y(other.y), z(other.z) {}

    // Overloading the + operator for vector addition
    vector3 operator+(const vector3& other) const;

    // Overloading the - operator for vector subtraction
    vector3 operator-(const vector3& other) const;

    // Overloading the * operator for dot product
    float operator*(const vector3& other) const;

    // Overloading the * operator for scalar multiplication
    vector3 operator*(float scalar) const;

    // Function for cross product
    vector3 cross(const vector3& other) const;

    // Overloading the << operator for output stream insertion
    friend std::ostream& operator<<(std::ostream& out, const vector3& v) {
        out << '(' << v.x << ", " << v.y << ", " << v.z << ')';
        return out;
    }

    static vector3 from_string(std::string string);
};

#endif