#pragma once

typedef int TElement;

class DynamicVector
{
private:
	TElement* elems;
	int size;
	int capacity;

public:
	// default constructor for a DynamicVector
	DynamicVector(int capacity = 10);

	~DynamicVector();

	// copy constructor
	DynamicVector(const DynamicVector& v);
	// move constructor
	DynamicVector(DynamicVector&& v);

	// copy assignment operator
	DynamicVector& operator=(const DynamicVector& v);
	// move assignment operator
	DynamicVector& operator==(DynamicVector&& v);

	// Adds an element to the current DynamicVector.
	void add(const TElement& e);

	DynamicVector operator+(const TElement& e);

	int getSize() const;
	TElement* getAllElems() const;

private:
	// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
	void resize(double factor = 2);
};

