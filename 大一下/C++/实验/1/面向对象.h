#pragma once
#include<iostream>
using namespace std;
#define PI 3.14


// Բ������
class Cylinder
{
public:
	// ���캯��
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


	// �޸İ뾶
	void SetRadius(double r)
	{
		this->radius = r;
	}

	// �޸ĸ�
	void SetHeight(double h)
	{
		this->height = h;
	}

	// ��ø�
	double GetHeight()
	{
		return this->height;
	}

	// ��ð뾶
	double GetRadius()
	{
		return this->radius;
	}

	// ��ȡ���
	double GetVolume()
	{
		return this->volume;
	}

	// ����
	~Cylinder()
	{

	}

private:
	double radius;
	double height;
	double volume;
};