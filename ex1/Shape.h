#pragma once
#include <string>
#include <algorithm>
#include <sstream>
#include <memory>
#include <vector>
#include <iostream>
using std::string;
class Shape
{
public:
	Shape(std::string name) :m_name(name){};
	virtual const double getArea() = 0;
	virtual const double getPerimeter() = 0;
	virtual void draw()const = 0;
	virtual void printDimensions()const = 0;
	const string & getName()const { return m_name; }
private:
	std::string m_name;
};
