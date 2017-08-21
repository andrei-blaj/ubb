#include "DynamicVector.h"
#include <iostream>

DynamicVector::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];

	std::cout << "Default constructor called" << std::endl;
}

DynamicVector::DynamicVector(const DynamicVector& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	std::cout << "Copy constructor called" << std::endl;
}

DynamicVector::~DynamicVector()
{
	delete[] this->elems;
	std::cout << "Destructor called" << std::endl;
}

DynamicVector& DynamicVector::operator=(const DynamicVector& v)
{
	std::cout << "Assignment operator called" << std::endl;

	if (this == &v)
		return *this;
	
	this->size = v.size;
	this->capacity = v.capacity;
	
	delete[] this->elems;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

DynamicVector::DynamicVector(DynamicVector && v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = v.elems;

	v.elems = nullptr;
	v.size = 0;
	v.capacity = 0;

	std::cout << "Move constructor called" << std::endl;
}


DynamicVector& DynamicVector::operator==(DynamicVector && v)
{
	std::cout << "Move assignment operator called" << std::endl;

	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;
	delete this->elems;
	this->elems = v.elems;

	// release the pointer
	v.elems = nullptr;
	v.size = 0;
	v.capacity = 0;

	return *this;
}

void DynamicVector::add(const TElement& e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

DynamicVector DynamicVector::operator+(const TElement & e)
{
	DynamicVector res = *this;
	res.add(e);
	return res;
}

void DynamicVector::resize(double factor)
{
	this->capacity *= factor;
	
	TElement* els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = els[i];

	delete[] this->elems;
	elems = els;
}

TElement* DynamicVector::getAllElems() const
{
	return this->elems;
}

int DynamicVector::getSize() const
{
	return this->size;
}