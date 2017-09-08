#include <Windows.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <assert.h>
#include <deque>
#include <string>
#include "BeverageMachine.h"

bool fct1(const std::vector<int>& v)
{
	int res = 0;
	for (auto it = v.begin(); it != v.end(); it++)
	{
		if (*it % 10 == 0)
			res++;
	}
	return (res == 0);
}

// ******************************************************************************************************************************************************

/*
	Filters all the elements from a vector of strings that contain exactly a given number of letters and copies them to a new vector.
	Input:	v - initial vector of strings;
			n - the number of letters (all strings in the initial vector are verified to see if they contain exactly n letters).
	Output: res - the filtered vector (containing only those strings which contain exactly n letters).
	Throws: std::exception, if the initial vector is empty.
*/
std::vector<std::string> filter(std::vector<std::string> v, int n)
{
	if (v.size() == 0)
		throw std::exception{ "The initial vector is empty!" };

	std::vector<std::string> res;
	std::copy_if(v.begin(), v.end(), std::back_inserter(res), [n](std::string s) {return s.size() == n; });
	return res;
}

void testFilter()
{
	std::vector<std::string> v{ "chicken", "dog", "wolf", "cat" };
	std::vector<std::string> res = filter(v, 3);
	assert(res.size() == 2);
	assert(res[0] == "dog");
	assert(res[1] == "cat");

	v.pop_back();
	res = filter(v, 3);
	assert(res[0] == "dog");

	res = filter(v, 10);
	assert(res.size() == 0);

	v.clear();
	try
	{
		res = filter(v, 3);
		assert(false);
	}
	catch (std::exception&)
	{
		assert(true);
	}
}

// ******************************************************************************************************************************************************
class B 
{
public:
	B() { std::cout << "B{}"; }
	virtual void print() { std::cout << "B"; }
	virtual ~B() { std::cout << "~B()"; }
};

class D : public B 
{
public:
	D() { std::cout << "D{}"; }
	void print() { std::cout << "D"; }
	virtual ~D() { std::cout << "~D()"; }
};

// ******************************************************************************************************************************************************

class Person
{
public:
	Person() { std::cout << "Person{}"; }
	virtual void print() = 0;
	virtual ~Person() { std::cout << "~Person()"; }
};

class Student : public Person
{
public:
	Student() { std::cout << "Student{}"; }
	void print() { std::cout << "Student"; }
	virtual ~Student() { std::cout << "~Student()"; }
};

// ******************************************************************************************************************************************************

class E
{
public:
	E() { std::cout << "E{}"; }
	virtual ~E() { std::cout << "~E()"; }
};

class DE : public E
{
public:
	static int n;
	DE() { n++; }
};

int DE::n = 0;

int fct2(int x)
{
	if (x < 0)
	{
		throw E{};
		std::cout << "number less than 0" << std::endl;
	}
	else if (x == 0)
	{
		throw DE{};
		std::cout << "number equal to 0" << std::endl;
	}
	return x % 10;
}


int main()
{
	system("color f4");

	int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	flag |= _CRTDBG_LEAK_CHECK_DF;
	_CrtSetDbgFlag(flag);


	// --------------------------------------------------------------------------------------------------------------------------------------------
	std::vector<int> v{ 1, 2, 3, 10, 2 };
	std::cout << fct1(v) << std::endl;

	// --------------------------------------------------------------------------------------------------------------------------------------------
	testFilter();

	// --------------------------------------------------------------------------------------------------------------------------------------------

	B* b[] = { new B{}, new D{} };
	b[0]->print();					
	b[1]->print();					
	delete b[0];					
	delete b[1];
	std::cout << std::endl;

	// --------------------------------------------------------------------------------------------------------------------------------------------
	
	std::cout << std::endl;
	//Person* p = new Person{};
	//delete p;
	Person* s = new Student{};
	s->print();
	delete s;
	std::cout << std::endl;

	// --------------------------------------------------------------------------------------------------------------------------------------------

	try
	{
		int res = 0;
		res = fct2(-5);		//res = fct2(-5);
		std::cout << DE::n;
		res = fct2(0);		//res = fct2(0);
		std::cout << DE::n;
		res = fct2(25);
		std::cout << DE::n;
	}
	catch (E&) 
	{
		std::cout << DE::n;
	}
	std::cout << std::endl;

	// --------------------------------------------------------------------------------------------------------------------------------------------

	std::deque<std::string> d;
	d.push_back("A");
	d.push_front("B");
	d.push_back("C");
	d.push_front("D");

	auto itBegin = d.begin();
	auto itEnd = d.end();
	itBegin++;
	itEnd--;

	while (itBegin != itEnd)
	{
		std::cout << *itBegin << " ";
		itBegin++;
	}
	std::cout << std::endl;

	// --------------------------------------------------------------------------------------------------------------------------------------------

	// Beverage machine
	BeverageMachine::prepare("Tea", 0);
	BeverageMachine::prepare("Coffee", 1);
	BeverageMachine::prepare("Coffee", 2);

	// --------------------------------------------------------------------------------------------------------------------------------------------

	system("pause");

	return 0;
}