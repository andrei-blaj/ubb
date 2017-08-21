#include <Windows.h>
#include <iostream>
#include "Spaceship.h"
#include "SpaceshipValidator.h"

using namespace std;

void exceptionHandling(bool throwEx) 
{
	try 
	{
		cout << "Code before the exception" << endl;
		if (throwEx) 
		{
			cout << "Throw exception" << endl;
			throw 12;
		}
		cout << "Code after the exception" << endl;
	}
	catch (int) 
	{
		cout << "Error handling code " << endl;
	}

	cout << "Done." << endl;
}

// -----------------------------------------------------------------------------------------------------------------------------

void exceptionExecutionFlowFct1()
{
	cout << "Function 1: code before exception." << endl;
	throw string{"exception"};
}

void exceptionExecutionFlowFct2()
{
	try
	{
		exceptionExecutionFlowFct1();
	}
	catch (int&) // trying to catch a type different than the type that was thrown
	{
		cout << "Tried to catch an integer." << endl;
	}
	catch (string&)
	{
		cout << "Exception in function exceptionExecutionFlowFct1 is being handled." << endl;
		//throw; // re-throw exception - cannot be handled by the same try-catch block
	}
	catch (...)
	{
		cout << "Caught exception." << endl;
	}
}

// -----------------------------------------------------------------------------------------------------------------------------

class A
{
private:
	int x;

public:
	A() : x{ 0 } {}
};

class B : public A {};

void multipleHandlers(string type)
{
	try
	{
		if (type == "A")
			throw A{};
		else if (type == "B")
			throw B{};
		else
			throw 20;
	}
	catch (A&)
	{
		cout << "Caught object of type A."<<endl;
	}
	catch (B&)
	{
		cout << "Caught object of type B." << endl;
	}
	catch (...)
	{
		cout << "Caught object of unknown type." << endl;
	}
}

// -----------------------------------------------------------------------------------------------------------------------------
// user defined exceptions

void testSpaceshipException()
{
	Spaceship deathStar{ "Death Star", "darth Vader", "dreadnought" };
	try
	{
		SpaceshipValidator::validate(deathStar);
	}
	//catch (ValidationException& ex)
	//catch (ValidationExceptionInherited& ex)
	catch (exception& ex)
	{
		//cout << ex.getMessage() << endl;
		cout << ex.what() << endl;
	}
}

// -----------------------------------------------------------------------------------------------------------------------------

int main()
{
	system("color f4");

	exceptionHandling(true);
	exceptionHandling(false);
	system("cls");

	exceptionExecutionFlowFct2();
	system("cls");

	multipleHandlers("A");
	multipleHandlers("B");
	multipleHandlers("");
	system("cls");
	
	testSpaceshipException();

	system("pause");

	return 0;
}