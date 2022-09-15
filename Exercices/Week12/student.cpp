#include "student.hpp"

Student::Student(const char* name, const int fn) 
    : Person(name), fn(fn)
{ }

int Student::getFN() const
{
    return this->fn;
}

void Student::readDirect(std::istream& in)
{
    if(&in == &std::cin) std::cout << "faculty number: ";
    in >> this->fn;
}

void Student::read(std::istream& in)
{
    Person::read(in);
    this->readDirect(in);
}

void Student::printDirect(std::ostream& out) const
{
    if(&out == &std::cout) std::cout << "faculty number: ";
    out << this->fn;
}

void Student::print(std::ostream& out) const
{
    Person::print(out);

    if(&out == &std::cout) out << ", ";
    else out << " ";
    
    this->printDirect(out);
    out << std::endl;
}
