#pragma once
#include "Shape.h"

class Add :public Shape
{
public:
	Add(std::shared_ptr<Shape> s1,std::shared_ptr<Shape> s2);
	virtual const double getArea();
	virtual const double getPerimeter();
	virtual void draw()const;
	virtual void printDimensions()const;

private:
	std::shared_ptr<Shape> m_s1;
	std::shared_ptr<Shape> m_s2;
};

