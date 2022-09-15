#include "assistant.hpp"

Assistant::Assistant()
    : Person(""), Student("", 0), Teacher("", 0)
{ }

Assistant::Assistant(const char* name, const int number, const double salary)
    : Person(name), Student(name, number), Teacher(name, salary)
{ }

void Assistant::read(std::istream& in)
{
    Person::read(in);
    Student::readDirect(in);
    Teacher::readDirect(in);
}

void Assistant::print(std::ostream& out) const
{
    Person::print(out);

    if(&out == &std::cout) out << ", ";
    else out << " ";

    Student::printDirect(out);

    if(&out == &std::cout) out << ", ";
    else out << " ";
    
    Teacher::printDirect(out);
    out << std::endl;
}
