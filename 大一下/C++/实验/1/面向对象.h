#pragma once
#include<iostream>
using namespace std;
#define PI 3.14


// 圆柱体类
class Cylinder
{
public:
	// 构造函数
	Cylinder()
	{
		this->radius = 0;
		this->height = 0;
		this->volume = 0;
	}

	Cylinder(double radius, double height)
	{
		this->radius = radius;
		this->height = height;
		this->volume = PI * this->radius * this->radius * this->height;
	}

	Cylinder(Cylinder& c)
	{
		this->radius = c.GetRadius();
		this->height = c.GetHeight();
		this->volume = c.GetVolume();
	}


	// 修改半径
	void SetRadius(double r)
	{
		this->radius = r;
	}

	// 修改高
	void SetHeight(double h)
	{
		this->height = h;
	}

	// 获得高
	double GetHeight()
	{
		return this->height;
	}

	// 获得半径
	double GetRadius()
	{
		return this->radius;
	}

	// 获取体积
	double GetVolume()
	{
		return this->volume;
	}

	// 析构
	~Cylinder()
	{

	}

private:
	double radius;
	double height;
	double volume;
};