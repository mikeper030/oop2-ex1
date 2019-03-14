#pragma once
#include "Shape.h"
class Triangle :public Shape
{
public:
	Triangle(double m_width ,double m_height);
	virtual const double getArea();
	virtual const double getPerimeter();
	virtual void draw()const;
	virtual void printDimensions()const;
private:
	double m_width;
	double m_height;
};

