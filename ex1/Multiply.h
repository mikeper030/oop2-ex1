#pragma once
#include "Shape.h"
class Multiply :public Shape
{
public:
	Multiply(std::shared_ptr<Shape> s1, int times);
	virtual const double getArea();
	virtual const double getPerimeter();
	virtual void draw()const;
	virtual void printDimensions()const;

private:
	std::shared_ptr<Shape> m_s1;
	int m_times;
};

