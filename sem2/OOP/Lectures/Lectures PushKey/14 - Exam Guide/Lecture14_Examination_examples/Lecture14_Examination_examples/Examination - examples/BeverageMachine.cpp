#include "BeverageMachine.h"
#include <iostream>

using namespace std;

Beverage::Beverage(): description{""}
{
}

Beverage::Beverage(const std::string & desc): description {desc}
{
}

Beverage::~Beverage()
{
}

void Beverage::print()
{
	cout << this->description << " " << this->price();
}

Coffee::Coffee(): Beverage{"Coffee"}
{
}

double Coffee::price()
{
	return 2.5;
}

Tea::Tea(): Beverage{"Tea"}
{
}

double Tea::price()
{
	return 1.5;
}

BeverageWithMilk::BeverageWithMilk(Beverage * b, int milkC) : beverage{ b }, milkCount{milkC}
{
}

void BeverageWithMilk::print()
{
	if (this->beverage == nullptr)
		return;
	this->beverage->print();
	cout << "; ";
	if (this->milkCount > 0)
		cout << " + " << this->milkCount << " portion(s) of milk." << "\t";
	cout << "Total price: " << this->price();
}

double BeverageWithMilk::price()
{
	if (this->beverage == nullptr)
		return 0;
	return this->beverage->price() + 0.5 * this->milkCount;
}

void BeverageMachine::prepare(std::string beverageType, int milkCount)
{
	if (beverageType != "Coffee" && beverageType != "Tea")
		return;
	Beverage* b = nullptr;
	if (beverageType == "Coffee")
		b = new Coffee{};
	else
		b = new Tea{};
	Beverage* bevMilk = new BeverageWithMilk{ b, milkCount };
	bevMilk->print();
	cout << endl;

	delete bevMilk;
	delete b;
}
