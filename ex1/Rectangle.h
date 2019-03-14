#pragma once
#include "Shape.h"
class Rectangle :public Shape
{
public:
	Rectangle(double ,double );
	virtual const double getArea();
	virtual const double getPerimeter();
	virtual void draw()const;
	virtual void printDimensions()const;
	
private:
	double m_height;
	double m_width;

};

