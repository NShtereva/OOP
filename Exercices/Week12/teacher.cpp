#include "teacher.hpp"

Teacher::Teacher(const char* name, const double salary)
    : Person(name), salary(salary)
{ }

double Teacher::getSalary() const
{
    return this->salary;
}

void Teacher::readDirect(std::istream& in)
{
    if(&in == &std::cin) std::cout << "salary: ";
    in >> this->salary;
}

void Teacher::read(std::istream& in)
{
    Person::read(in);
    this->readDirect(in);
}

void Teacher::printDirect(std::ostream& out) const
{
    if(&out == &std::cout) std::cout << "salary: ";
    out << this->salary;
}

void Teacher::print(std::ostream& out) const
{
    Person::print(out);

    if(&out == &std::cout) out << ", ";
    else out << " ";
    
    this->printDirect(out);
    out << std::endl;
}
