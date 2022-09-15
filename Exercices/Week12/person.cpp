#include "person.hpp"

#include <iostream>
#include <cstring>

Person::Person(const char* name) : name(nullptr)
{
    this->setName(name);
}

Person::Person(const Person& other) : name(nullptr)
{
    this->setName(other.name);
}

Person::~Person()
{
    delete[] this->name;
    this->name = nullptr;
}

Person& Person::operator = (const Person& other)
{
    if(this != &other)
    {
        this->setName(other.name);
    }
    return *this;
}

const char* Person::getName() const
{
    return this->name;
}

void Person::setName(const char* name)
{
    if(!name || strlen(name) > MAX_NAME_LEN) name = "";

    delete[] this->name;

    this->name = new(std::nothrow) char[strlen(name) + 1];
    if(!this->name)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    strcpy(this->name, name);
}

void Person::read(std::istream& in)
{
    char buffer[MAX_NAME_LEN];

    if(&in == &std::cin) 
    {
        std::cout << "name: ";
        in.getline(buffer, MAX_NAME_LEN);
    }
    else
    {
        in.getline(buffer, MAX_NAME_LEN, '|');
    }

    this->setName(buffer);
}

void Person::print(std::ostream& out) const
{
    if(&out == &std::cout) out << "name: ";

    out << this->name;

    if(&out != &std::cout) out << "|";
}
