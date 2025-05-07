#pragma once
#include <iostream>  
#include <string>
using namespace std;

// 汽车基类  
class Car {
public:
    // 构造函数  
    Car(){}
    Car(const string& make, const string& model)
        : make(make), model(model) {}

    // 虚析构函数，确保在删除派生类对象时正确调用析构函数  
    virtual ~Car() {}

    // 虚函数示例：打印汽车信息  
    virtual void PrintInfo() const {
        cout << "Make: " << this->make << ", Model: " << this->model << endl;
    }

    // 纯虚函数示例：定义了一个所有汽车都应该实现的行为，但基类不提供具体实现  
    virtual void SpecialFeature() const = 0;

protected:
    string make;
    string model;
};

// 货车类，继承自汽车类  
class Truck : virtual public Car { // 使用虚继承  
public:
    Truck(const string& make, const string& model, float cargoCapacity)
        : Car(make, model), cargoCapacity(cargoCapacity) {}

    void PrintInfo() const override {
        Car::PrintInfo();
        cout << "Cargo Capacity: " << this->cargoCapacity << " tons" << endl;
    }

    void SpecialFeature() const override {
        cout << "Truck Special Feature: Large cargo space." << endl;
    }

private:
    float cargoCapacity;
};

// 客车类，继承自汽车类  
class Bus : virtual public Car { // 使用虚继承  
public:
    Bus(const string& make, const string& model, int passengerCapacity)
        : Car(make, model), passengerCapacity(passengerCapacity) {}

    void PrintInfo() const override {
        Car::PrintInfo();
        cout << "Passenger Capacity: " << this->passengerCapacity << " persons" << endl;
    }

    void SpecialFeature() const override {
        cout << "Bus Special Feature: Can carry many passengers." << endl;
    }

private:
    int passengerCapacity;
};

// 皮卡车类，继承自货车和客车类，体现了虚基类的作用（避免多重继承带来的成员冲突）  
class PickupTruck : public Truck, public Bus {
public:
    PickupTruck(const string& make, const string& model, float cargoCapacity, int passengerCapacity)
        : Truck(make, model, cargoCapacity), Bus(make, model, passengerCapacity){}

    void PrintInfo() const override {
        Truck::PrintInfo(); // 或者使用 Bus::PrintInfo()，两者在这个例子中是等效的，因为Truck和Bus都继承自Car，且都重写了PrintInfo()  
        cout << "This is a PickupTruck!" << endl;
    }

    void SpecialFeature() const override {
        cout << "PickupTruck Special Feature: Combines cargo space and passenger carrying capability." << endl;
    }
};
