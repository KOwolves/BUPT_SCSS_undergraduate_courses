#pragma once
#include<iostream>
using namespace std;

class Point3D {
public:
    double x, y, z;

    Point3D(double x = 0.0, double y = 0.0, double z = 0.0) : x(x), y(y), z(z) {}

    // �ӷ����������  
    Point3D operator+(const Point3D& other) const {
        return Point3D(x + other.x, y + other.y, z + other.z);
    }

    // �������������  
    Point3D operator-(const Point3D& other) const {
        return Point3D(x - other.x, y - other.y, z - other.z);
    }

    // ��ֵ���������  
    Point3D& operator=(const Point3D& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }

    // ������������أ�ǰ׺��  
    Point3D& operator++() {
        ++x;
        ++y;
        ++z;
        return *this;
    }

    // ������������أ���׺��  
    Point3D operator++(int) {
        Point3D temp = *this;
        ++x;
        ++y;
        ++z;
        return temp;
    }

    // �Լ���������أ�ǰ׺��  
    Point3D& operator--() {
        --x;
        --y;
        --z;
        return *this;
    }

    // �Լ���������أ���׺��  
    Point3D operator--(int) {
        Point3D temp = *this;
        --x;
        --y;
        --z;
        return temp;
    }

    // �±����������  
    const double& operator[](int index) const {
        switch (index) {
        case 0: return x;
        case 1: return y;
        case 2: return z;
        default: throw out_of_range("Index out of bounds");
        }
    }
};