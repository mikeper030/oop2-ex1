#include "Multiply.h"

using std::string;
/////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////

Multiply::Multiply(std::shared_ptr<Shape> s1 , int times)
	:m_s1(s1),m_times(times)
	,Shape(string("Multiple (").append(s1->getName()).append(" * ").append(std::to_string(times)).append(")"))
{
}
/////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////

 const double Multiply::getArea()
{
	return m_s1->getArea()*m_times;
}
/////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////

 const double Multiply::getPerimeter()
{
	return m_s1->getPerimeter()*m_times;
}
/////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////

void Multiply::draw() const
{
	m_s1->printDimensions();
	std::cout<<" * ("<<m_times<<") times " << std::endl;
	m_s1->draw();

}
/////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////

void Multiply::printDimensions() const
{
	m_s1->printDimensions();
	std::cout << " * (" << m_times << ")  times" << std::endl;
}
/////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////
