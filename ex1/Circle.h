#pragma once
#include "Shape.h"
class Circle :public Shape
{
public:
	Circle(double radius);
	virtual const double getArea();
	virtual const double getPerimeter();
	virtual void draw()const;
	void printDimensions() const;
	
private:
	double m_raduis;
};

