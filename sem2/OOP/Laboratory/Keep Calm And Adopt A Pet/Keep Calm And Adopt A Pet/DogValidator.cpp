#include "DogValidator.hpp"

using namespace std;

DogException::DogException(std::vector<std::string> _errors) : errors{ _errors }
{
}

std::vector<std::string> DogException::getErrors() const
{
    return this->errors;
}

void DogValidator::validate(const Dog & d)
{
    vector<string> errors;
    if (d.getBreed().size() < 3)
        errors.push_back("The breed cannot be less than 2 characters!\n");
    if (!isupper(d.getName()[0]))
        errors.push_back(string("The name of the dog must start with a capital letter!\n"));
    if (d.getAge().getYears() == 0 && d.getAge().getMonths() == 0 && d.getAge().getDays()==0)
        errors.push_back(string("The age cannot be 0!\n"));
    
    // search for "www" or "http" at the beginning of the source string
    int posWww = d.getPhotograph().find("www");
    int posHttp = d.getPhotograph().find("http");
    if (posWww != 0 && posHttp != 0)
        errors.push_back("The youtube source must start with one of the following strings: \"www\" or \"http\"");
    
    if (errors.size() > 0)
        throw DogException(errors);
}
