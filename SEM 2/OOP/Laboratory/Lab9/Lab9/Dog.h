#pragma once
#include <iostream>

class Age
{
private:
	int years;
	int months;
	int days;
public:
	Age() : years(0), months(0), days(0) {}
	Age(int y, int mon, int d) : years(y), months(mon), days(d) {}

	int getYears() const { return years; }
	int getMonths() const { return months; }
	int getDays() const { return days; }
	void setYears(int y) { years = y; }
	void setMonths(int mon) { months = mon; }
	void setDays(int d) { days = d; }
};

class Dog
{//modif
protected:
	std::string breed;
	std::string name;
	Age age;
	std::string photograph;		//  a link towards an online resource

public:
	// default constructor for a dog
	Dog();

	// constructor with parameters
	Dog(const std::string& breed, const std::string& name, const Age& age, const std::string& photograph);

	// copy constructor
	//modif
	Dog(const Dog& d);
	//modif
	// destructor
	//~Dog();

	std::string getBreed() const { return breed; }
	std::string getName() const { return name; }
	Age getAge() const { return age; }
	std::string getPhotograph() const { return photograph; }

	// Shows the current dog: the page corresponding to the source link is opened in a browser.
	void showPhotograph();

	friend std::istream& operator>>(std::istream& is, Dog& d);
	friend std::ostream& operator<<(std::ostream& os, const Dog& d);
};


