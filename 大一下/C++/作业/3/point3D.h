#pragma once
#include<iostream>
using namespace std;

class Point3D {
public:
    double x, y, z;

    Point3D(double x = 0.0, double y = 0.0, double z = 0.0) : x(x), y(y), z(z) {}

    // 加法运算符重载  
    Point3D operator+(const Point3D& other) const {
        return Point3D(x + other.x, y + other.y, z + other.z);
    }

    // 减法运算符重载  
    Point3D operator-(const Point3D& other) const {
        return Point3D(x - other.x, y - other.y, z - other.z);
    }

    // 赋值运算符重载  
    Point3D& operator=(const Point3D& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }

    // 自增运算符重载（前缀）  
    Point3D& operator++() {
        ++x;
        ++y;
        ++z;
        return *this;
    }

    // 自增运算符重载（后缀）  
    Point3D operator++(int) {
        Point3D temp = *this;
        ++x;
        ++y;
        ++z;
        return temp;
    }

    // 自减运算符重载（前缀）  
    Point3D& operator--() {
        --x;
        --y;
        --z;
        return *this;
    }

    // 自减运算符重载（后缀）  
    Point3D operator--(int) {
        Point3D temp = *this;
        --x;
        --y;
        --z;
        return temp;
    }

    // 下标运算符重载  
    const double& operator[](int index) const {
        switch (index) {
        case 0: return x;
        case 1: return y;
        case 2: return z;
        default: throw out_of_range("Index out of bounds");
        }
    }
};