#include <cstdio>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <windows.h>
#include <locale.h>
#include <fstream>

class Figure
{
public:

	Figure() { sides_count = 0; this->name = "Фигура:"; };

	int get_sides_count()
	{
		return sides_count;
	}

	std::string get_name()
	{
		return name;
	}
private:


protected:
	int sides_count;
	std::string name;
};



class Triangle : public Figure
{
public:
	Triangle() { sides_count = 3; this->name = "Треугольник:"; };

private:

};



class Quadrangle : public Figure
{
public:
	Quadrangle() { sides_count = 4; this->name = "Четырехугольник:";	};

private:

};



int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//std::string q = "привт";
	//std::string w = "Hello";
	//std::string e;
	//std::cout << q << " " << w << " " << std::endl;
	//std::cin >> e;
	//std::cout << e;


	
	Quadrangle q = {};
	Triangle t = {};
	Figure f = {};

	std::cout << "Количество сторон:" << std::endl<< f.get_name() << " "<<f.get_sides_count() << "\n" 
			  << t.get_name() << " " << t.get_sides_count() << "\n"
			  <<q.get_name()<<" "<<q.get_sides_count()<<std::endl;


	return 0;
}