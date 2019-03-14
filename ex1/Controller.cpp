#include "Controller.h"
#include <map>

using std::cout;
using std::cin;
using std::endl;
/////////////////////////////////////////////////////
//default constructor
/////////////////////////////////////////////////////

Controller::Controller()
{
}
/////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////

void Controller::command()
{
	
	std::string command1,command2;
	
	do
	{
		int i = 0;
		std::cout << "This is the shapes list:\n";
		for (auto &e : m_v)
		{
			std::cout << i++<<" : ";
			e->printDimensions();
			std::cout<< "\n";
		}
                std::cout << "\n" << "Please enter a command ('help' for command list): ";				
				std::cin >> command1>>command2;
				std::transform(command1.begin(), command1.end(), command1.begin(), ::tolower);
				

				if (command1 == "help")
				{
					help();
				}
				if (command1 == "cre")
				{
					create(command2);	
				}
				if (command1 == "area")
				{
					
					area(std::stoi(command2));
				}
				if (command1 == "mul")
				{
					mull(std::stoi(command2));
				}
				if (command1 == "add")
				{
					add(std::stoi(command2));
				}
				if (command1 == "sub")
				{
					sub(std::stoi(command2));
				}
				if (command1 == "min")
				{
					std::cout<<min()<<std::endl;
				}
				if (command1 == "max")
				{
					std::cout<<max() << std::endl;
				}
				if (command1 == "draw")
				{
					draw(std::stoi(command2));
				}
				if (command1 == "same")
				{
					cout << "which number do you want to check :" << endl;
					
					same(std::stoi(command2));
				}
				if (command1 == "del")
				{
					int index;
					cout << "Enter the number of the shape from the list:\n";
					cin >> index;
					m_v.erase(m_v.begin() + index);
				}
	} while (command1 != "exit");

	cout << "goodbye";
}
/////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////

void Controller::help()
{
	std::cout << "\n" << R"(Following is the list of the calculator's available commands:
 cre(ate) #shape <R - rectangle | T-triangle | C- circle>
 area num - Computes the area of shape #num
 per(imeter) num - Computes the perimeter of shape #num
 draw num - Draw the shape #num
 mul(tiply) num x - Creates a function that is the multiplication         
 of shape #num x times 
add num1 num2 - Creates a function that is the sum of function             
#num1 and function #num2 
sub num1 num2 - Creates a function that is the subtraction of           
function #num1 and function #num2 
min n #num1-#numN - Returns the smallest area in the chosen          
shapes. n - the requested shapes: #num1...  
max n #num1-#numN - Returns the biggest area in the chosen shapes.            
n - the requested shapes: #num1... 
same num - Returns shapes with which have the same area and            
perimeter to the shape #num  
del(ete) num - Deletes function #num from function list 
help - Prints this help screen 
exit - Exits the program 
This is the shapes list: 
Please enter a command ("help" for command list): )";

}
/////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////

void Controller::create(std::string & command)
{
	if (command == "r")
	{
		double h, w;
		cout << "Enter height then width\n";
		cin >> h >> w;
		m_v.push_back(std::make_shared<Rectangle>(h, w));
	}
	if (command == "c")
	{
		double r;
		cout << "Enter raduis\n";
		cin >> r;
		m_v.push_back(std::make_shared<Circle>(r));
	}
	if (command == "t")
	{
		int l, h;
		cout << "Enter height then width\n";
		cin >> l >> h;
		m_v.push_back(std::make_shared<Triangle>(l, h));
	}
}
/////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////

void Controller::add(int arg1)
{
	int arg2;
	cin >> arg2;
	m_v.push_back(std::make_shared<Add>(m_v[arg1], m_v[arg2]));
}
/////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////

void Controller::mull(int arg1)
{
	int mul;
	cin  >> mul;
	m_v.push_back(std::make_shared<Multiply>(m_v[arg1],mul));
}
/////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////

void Controller::sub(int arg1)
{
	int  arg2;
	cin >> arg2;
	m_v.push_back(std::make_shared<Sub>(m_v[arg1], m_v[arg2]));
}
/////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////

void Controller::area(int index)
{
	for (int i=0 ;i<m_v.size();i++)
	{
		if (i == index)
		{
			std::cout << "Area ";
			m_v[i]->printDimensions(); std::cout << " = ";
			std::cout<< m_v[i]->getArea()<<std::endl;
		}
	}
}
/////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////

int Controller::max()
{
	int _max = 0;
	for (int i = 0; i < m_v.size(); i++)
	{
		if (m_v[i]->getArea() > _max)
		{
			_max = m_v[i]->getArea();
		}
	}
	return _max;
}
/////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////

int Controller::min()
{
	int minimum=100;
	for (int i = 0; i < m_v.size(); i++)
	{
		if (m_v[i]->getArea() < minimum)
		{
			minimum = m_v[i]->getArea();
		}
	}
	return minimum;
}
/////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////

void Controller::draw(int n)
{
	for (int i = 0; i < m_v.size(); i++)
	{
		if (i == n)
			m_v[i]->draw();
	}
}
/////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////

void Controller::same(int n)
{
	double _area = m_v[n]->getArea(), _per = m_v[n]->getPerimeter();
	for (int i = 0; i < m_v.size(); i++)
	{
		if (m_v[i]->getArea() == _area && m_v[i]->getPerimeter() == _per && i!=n) {
			cout << i << " ";
			m_v[i]->printDimensions();
			cout << endl;
		}

	}
}

