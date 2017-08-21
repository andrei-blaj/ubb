#pragma once
#include <string>
#include "Dog.h"
#include <vector>

class DogException
{
private:
	std::vector<std::string> errors;

public:
	DogException(std::vector<std::string> _errors);
	std::vector<std::string> getErrors() const;
};

class DogValidator
{
public:
	DogValidator() {}
	static void validate(const Dog& d);
};


