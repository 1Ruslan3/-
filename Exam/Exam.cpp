#include <iostream>
#include<cstring>
#include<ctime>
#include<time.h>
#include<stack>
//#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace std; 

class Student
{
	string name;
	string firstName;
public:
	Student(string name, string firstName)
	{
		cout << "Constructor" << this << endl;
		this->firstName = firstName;
		this->name = name;
	}
	void show()
	{
		cout << firstName << " " << name << endl;
	}
	~Student()
	{
		cout << "Destructor" << this << endl;
	}
	Student (const Student& value)
	{
		cout << "Constructor copy" << this << endl;
		name = value.name;
		firstName = value.firstName;
	}
};

class Array
{
	int* p;
	int size;
public:
	Array(int sz)
	{
		p = new int[sz];
		if (!p) exit(1);
		size = sz;
		cout << "Simple constructor" << endl;
	}
	~Array()
	{
		cout << "Destructor" << endl;
		delete[] p;
	}
	void put(int i, int j)
	{
		if (i >= 0 && i < size)
		{
			p[i] = j;
		}
	}
	int get(int i)
	{
		return p[i];
	}
	Array(const Array& value)
	{
		int i;
		size = value.size;
		p = new int[value.size];
		if (!p) exit(1);
		for (i = 0; i < value.size; i++)
		{
			p[i] = value.p[i];
		}
		cout << "Constructor copy" << endl;
	}

	Array& operator =(const Array& value)
	{
		int i;
		size = value.size;
		if (this->p != nullptr)
		{
			delete[] p;
		}
		this->p = new int[value.size];
		for (i = 0; i < size; i++)
		{
			this->p[i] = value.p[i];
		}
		return *this;
	}
};

class Point
{
	int a;
	int b;
public:
	Point()
	{
		a = 0;
		b = 0;
	}
	Point(int a, int b)
	{
		this->a = a;
		this->b = b; 
	}

	Point operator +(const Point& value)
	{
		Point temp;
		temp.a = this->a + value.a;
		temp.b = this->b + value.b;
		return temp;
	}

	bool operator ==(const Point& value)
	{
		return this->a == value.a && this->b == value.b;
	}

	bool operator !=(const Point& value)
	{
		return !(this->a == value.a && this->b == value.b);
	}


	void Show()
	{
		cout << a << " " << b << endl;
	}
};

int x;
int& f()
{
	return x;
}

int sum(int x, int y)
{
	return x + y;
}

double sum(double x, double y)
{
	return x + y;
}

double sum(double x, double y, double z)
{
	return x + y + z;
}

int main()
{
	
	Array num(10);
	int i;
	for (i = 0; i < 10; i++)
	{
		num.put(i, i);
		cout << num.get(i);
	}
	cout << endl;

	Array num1 = num;

	for (i = 0; i < 10; i++)
	{
		cout << num1.get(i);
	}

	Array num2(10); 

	num2 = num1;


	cout << endl;


	Student st("Ruslan", "Keshabyan");
	Student st1 = st;
	st1.show();


	char arr[] = "Hello";
	char* ptr;
	ptr = new char[10];
	strcpy(ptr, arr);
	cout << ptr << endl;
	delete[] ptr;


	f() = 100;
	cout << x << endl;

	Point a(13, 13);
	Point b(10, 10);
	Point c = a + b;
	c.Show();

	bool result = a == b;

	cout << result << endl;

	double tr1 = 10, tr2 = 0, tr3 = 3;

	cout << sum(tr1, tr2, tr3) << endl;

	stack<int> stack;

	stack.push(1);
	stack.push(2);
	stack.push(3);
	cout << stack.top() << endl;

	f() = 3;


	return 0;
}


