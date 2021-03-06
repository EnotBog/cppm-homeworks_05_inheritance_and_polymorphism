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
		std::cout << get_name() << "\n" << check << "\n" <<"Количество сторон: "<<sides_count << "\n " << get_corn() << get_sides() << "" << "\n";//
	}

	virtual bool true_or_false() 
	{
		return true;
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
	std::string check;
};


class Triangle : public Figure //треугольник скц
{
public:
	Triangle() { sides_count = 3; }
	Triangle(int a,int b,int c, int A, int B, int C) 
	{
		this->a = a; this->b = b; this->c = c; 
		this->A = A; this->B = B; this->C = C; 
		this->name = "Треугольник:";
		this->sides_count = 3;
		true_or_false();
		
	};

protected:
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
		std::cout << Triangle::get_name() <<"\n" << this->check << "\n" << "Количество сторон: " << sides_count << "\n" << Triangle::get_sides() << Triangle::get_corn() << "" << " " << " " << "\n"; // 
	}

	bool true_or_false() override
	{
		if((A+B+C)==180)
		{
			this->check = "Правильная";
			return true;
		}
		else 
		{
			this->check = "Неправильная";
			return false; 
		}
	}
	

	int a=0, b=0, c=0;
	int A=0, B=0, C=0;

private:

};

class Equilateral_triangle:public Triangle //равносторонний треугольник
{
public:
	Equilateral_triangle(int a):Triangle( a,a,a,60,60,60)
	{
		this->name = "Равносторонний треугольник: ";
		true_or_false();

	}
protected:

	bool true_or_false() override
	{
		if ((Triangle::true_or_false()) && (a==b)&&(b==c)&&(c==a))
		{
			this->check = "Правильная";
			return true;
		}
		else
		{
			this->check = "Неправильная";
			return false;
		}
	}

private:

};


class Isosceles_triangle:public Triangle // равнобедренный треугольник
{
public:
	Isosceles_triangle(int a,int b,int A,int B):Triangle(a,b,a,A,B,A)
	{
		this->name = "Равнобедренный треугольник: ";
		true_or_false();
	}
protected:
	bool true_or_false() override
	{
		if ((Triangle::true_or_false()) && (a==c)&&(A==C))
		{
			this->check = "Правильная";
			return true;
		}
		else
		{
			this->check = "Неправильная";
			return false;
		}
	}
private:

};


class Rectangular_triangle:public Triangle //прямоугольный треугольник
{
public:
	Rectangular_triangle(int a, int b, int c, int A, int B):Triangle(a,b,c,A,B,90)
	{
		this->name = "Прямоугольный треугольник: ";
		true_or_false();
	}

protected:
	bool true_or_false() override
	{
		if ((Triangle::true_or_false()) && (C == 90))
		{
			this->check = "Правильная";
			return true;
		}
		else
		{
			this->check = "Неправильная";
			return false;
		}
	}
private:

};



class Quadrangle : public Figure
{
public:
	Quadrangle() { };

	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
	{
		this->a = a; this->b = b; this->c = c; this->d = d;
		this->A = A; this->B = B; this->C = C; this->D = D;
		this->name = "Четырехугольник:";
		this->sides_count = 4;
		true_or_false();
	}

protected:
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
	void print_info() override
	{
		std::cout << Quadrangle::get_name() << "\n" << this->check << "\n" << "Количество сторон: " << sides_count << "\n"  << Quadrangle::get_sides() << Quadrangle::get_corn() << "" << "\n"; // 
	}

	bool true_or_false() override
	{
		if ((A+B+C+D)==360) 
		{
			this->check = "Правильная";
			return true;
		}
		else
		{
			this->check = "Неправильная";
			return false;
		}
	}

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
		true_or_false();
	}


	//параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны)
protected:

	bool true_or_false() override
	{
		if ((Quadrangle::true_or_false())&&(a == c && b == d) && (A == C && B == D))
		{
			this->check = "Правильная";
			return true;
		}
		else
		{
			this->check = "Неправильная";
			return false;
		}
	}

private:

};

class My_Rectangle : public Parallelogram // Прямоугольник
{
public:
	My_Rectangle(int a, int b) :Parallelogram(a, b, 90, 90) 
	{
		this->name = "Прямоугольник: ";
		true_or_false();
	}

protected:
	
	bool true_or_false() override
	{
		if ((a == c && b == d) && a != b && (A == 90 && B == 90 && C == 90 && D == 90))
		{
			this->check = "Правильная";
			return true;
		}
		else
		{
			this->check = "Неправильная";
			return false;
		}
	}
private:

};

class Square : public My_Rectangle // квадрат
{
public:
	Square(int a) :My_Rectangle(a, a)
	{
		this->name = "Квадрат: ";
		true_or_false();
	}
protected:

	bool true_or_false() override
	{
		if ((a == c && b == d) && (a == b && c == d) && (A == 90 && B == 90 && C == 90 && D == 90))
		{
			this->check = "Правильная";
			return true;
		}
		else
		{
			this->check = "Неправильная";
			return false;
		}
	}
private:
};

class Rhomb: public Parallelogram //ромб
{
public:
	Rhomb(int a, int A, int B) : Parallelogram(a, a, A, B)
	{
		this->name = "Ромб: ";
		true_or_false();
	}

protected:

	bool true_or_false() override
	{
		if ((a == c && b == d) && (a == b && c == d) && (A == C && B == D)&&(A+B==180))
		{
			this->check = "Правильная";
			return true;
		}
		else
		{
			this->check = "Неправильная";
			return false;
		}
	}
private:

};





int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Figure f = {};
	Triangle triagle = {10,20,30,50,60,70};
	Rectangular_triangle r_triagle = {10,20,30,60,60};
	Isosceles_triangle i_triagle = { 10,20,50,60 }; 
	Equilateral_triangle e_triagle = { 10 };

	Quadrangle quadrangle = {10,20,30,40,100,100,70,80}; // четырех угольник
	Parallelogram parallelogram = { 20,30,30,40 }; //параллелограмм
	My_Rectangle rectangle = { 10,20 };//прямоугольник
	Square square = { 20 }; // квадрат
	Rhomb rhomb = {10,126,54}; // ромб

	
	Figure* p_triagle = &triagle;
	Figure* p_equilateral_triangle = &e_triagle;
	Figure* p_isosceles_triangle = &i_triagle;
	Figure* p_rectangular_triangle = &r_triagle;

	Figure* p_rectangle = &rectangle;
	Figure* p_quadrangle = &quadrangle;
	Figure* p_square = &square;
	Figure* p_parallelogram = &parallelogram;
	Figure* p_rhomb = &rhomb;
  
p_triagle->print_info();
p_rectangular_triangle->print_info();
p_isosceles_triangle->print_info();
p_equilateral_triangle->print_info();

p_quadrangle->print_info();
p_rectangle->print_info();
p_square->print_info();
p_parallelogram->print_info();
p_rhomb->print_info();



	return 0;
}