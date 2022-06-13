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

	
	
	virtual void print_info() 
	{
		std::cout << get_name() << "\n " << get_corn() << get_sides() << "" << "\n";//
	}

private:


protected:
	std::string get_sides()
	{
		return " ";
	}
	std::string get_corn()
	{
		return " ";
	}
	int get_sides_count()
	{
		return sides_count;
	}

	std::string get_name()
	{
		return name;
	}

	int sides_count;
	std::string name;
	std::string sides;
	std::string corn;
};


class Triangle : public Figure //треугольник скц
{
public:
	Triangle() { sides_count = 3; this->name = "Треугольник:"; };
	Triangle(int a,int b,int c, int A, int B, int C) 
	{
		this->a = a; this->b = b; this->c = c; 
		this->A = A; this->B = B; this->C = C; 
	};

	std::string get_sides()
	{
		std::string buf = { "Стороны: a=" + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c) + "\n" };
		return buf;
	}
	std::string get_corn()
	{
		std::string buf = { "Углы: A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C) + "\n" };
		return buf;
	}

	void print_info() override
	{
		std::cout << Triangle::get_name() << "\n" << Triangle::get_corn() << Triangle::get_sides() << "" << " " << " " << "\n"; // 
	}
	

protected:
	int a, b, c;
	int A, B, C;

private:

};

class Equilateral_triangle:public Triangle //равносторонний треугольник
{
public:
	Equilateral_triangle(int a):Triangle( a,a,a,60,60,60)
	{
		this->name = "Равносторонний треугольник: ";
	}
private:

};


class Isosceles_triangle:Triangle // равнобедренный треугольник
{
public:
	Isosceles_triangle(int a,int c,int A,int B):Triangle(a,a,c,A,B,A)
	{
		this->name = "Равнобедренный треугольник: ";
	}
private:

};


class Rectangular_triangle:public Triangle //прямоугольный треугольник
{
public:
	Rectangular_triangle(int a, int b, int c, int A, int B):Triangle(a,b,c,A,B,90)
	{
		this->name = "Прямоугольный треугольник: ";
	}
private:

};



class Quadrangle : public Figure
{
public:
	Quadrangle() { sides_count = 4; this->name = "Четырехугольник:"; };

	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
	{
		this->a = a; this->b = b; this->c = c; this->d = d;
		this->A = A; this->B = B; this->C = C; this->D = D;
	}

	std::string get_sides()
	{
		std::string buf = { "Стороны: a=" + std::to_string(a) + " b=" + std::to_string(b) + " c=" + std::to_string(c) + " d=" + std::to_string(d) + "\n" };
		return buf;
	}
	std::string get_corn()
	{
		std::string buf = { "Углы: A=" + std::to_string(A) + " B=" + std::to_string(B) + " C=" + std::to_string(C) + " D=" + std::to_string(D) + "\n" };
		return buf;
	}

protected:

	int a = 0, b = 0, c = 0, d = 0;
	int A = 0, B = 0, C = 0, D = 0;

private:


};

class Parallelogram : public Quadrangle // параллелограмм
{
public:
	Parallelogram(int a, int b, int A, int B) :Quadrangle(a, b, a, b, A, B, A, B)
	{
		this->name = "Параллелограм: ";
	}

	void print_info() override
	{
		std::cout << Quadrangle::get_name() << "\n" << Quadrangle::get_corn() << Quadrangle::get_sides() << "" << "\n"; // 
	}
private:

};

class My_Rectangle : public Parallelogram // Прямоугольник
{
public:
	My_Rectangle(int a, int b) :Parallelogram(a, b, 90, 90) 
	{
		this->name = "Прямоугольник: ";
	}


private:

};

class Square : public My_Rectangle // квадрат
{
public:
	Square(int a) :My_Rectangle(a, a)
	{
		this->name = "Квадрат: ";
	}
private:
};

class Rhomb: public Parallelogram //ромб
{
public:
	Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B)
	{
		this->name = "Ромб: ";
	}
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
	//Triangle t = {};
	Figure f = {};
	Parallelogram pr = { 0,0,0,0 };
	My_Rectangle rc = { 10,10 };
	Square sq = { 5 };
	Rhomb rh = { 5,90,90 };
	Equilateral_triangle et = { 10 };
	Isosceles_triangle it = { 10,20,70,40 };
	Rectangular_triangle rt = { 20,40,20,30,60 };

	//std::cout << "Количество сторон:" << std::endl << f.get_name() << " " << f.get_sides_count() << "\n"
	//	<< t.get_name() << " " << t.get_sides_count() << "\n"
	//	<< q.get_name() << " " << q.get_sides_count() << std::endl;

	/*std::cout <<pr.get_name() << " " << pr.get_corn() << pr.get_sides() << "" << " " << " " << "\n";
	std::cout << rc.get_name() << " "<<rc.get_corn() << rc.get_sides() << "" << " " << " " << "\n";
	std::cout << sq.get_name() << " "<< sq.get_corn() << sq.get_sides() << "" << " " << " " << "\n" << "\n";*/
	
	Figure* pSquare = &sq;
	Figure* pRhomb = &rh;
	Figure* pEquilateral_triangle = &et;
	
   pSquare->print_info();
   pRhomb->print_info();
   pEquilateral_triangle->print_info();

	return 0;
}