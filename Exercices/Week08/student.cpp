#include "student.hpp"

#include <cstring>
#include <cassert>

const size_t MAX_LEN = 1024;

Student::Student() : name(nullptr)
{
    this->setName("-");
    this->setFN(0);
    this->setGroup(0);
    this->setAverageGrade(2);
}

Student::Student(const char* name, const int fn, const int group, const double averageGrade)
    : name(nullptr)
{
    this->setName(name);
    this->setFN(fn);
    this->setGroup(group);
    this->setAverageGrade(averageGrade);
}

Student::Student(const Student& other) : name(nullptr)
{
    this->setName(other.name);
    this->setFN(other.fn);
    this->setGroup(other.group);
    this->setAverageGrade(other.averageGrade);    
}

Student::~Student()
{
    delete[] this->name;
    this->name = nullptr;
}

Student& Student::operator = (const Student& other)
{
    if(this != &other)
    {
        this->setName(other.name);
        this->setFN(other.fn);
        this->setGroup(other.group);
        this->setAverageGrade(other.averageGrade); 
    }

    return *this;
}

bool Student::operator < (const Student& other) const
{
    double eps = 0.001;
    
    return (std::abs(this->averageGrade - other.averageGrade) < eps) ? 
           this->fn < other.fn : 
           this->averageGrade < other.averageGrade;
}

bool Student::operator == (const Student& other) const
{
    return this->fn == other.fn;
}

const char* Student::getName() const
{
    return this->name;
}

unsigned Student::getFN() const
{
    return this->fn;
}

unsigned Student::getGroup() const
{
    return this->group;
}

double Student::getAverageGrade() const
{
    return this->averageGrade;
}

void Student::setName(const char* name)
{
    if(!name || strlen(name) > MAX_LEN) name = "";

    delete[] this->name;

    this->name = new(std::nothrow) char[strlen(name) + 1];
    if(this->name == nullptr)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    strcpy(this->name, name);
}

void Student::setFN(const int fn)
{
    assert(fn >= 0);
    this->fn = fn;
}

void Student::setGroup(const int group)
{
    assert(group >= 0);
    this->group = group;
}

void Student::setAverageGrade(const double averageGrade)
{
    assert(averageGrade >= 2 && averageGrade <= 6);
    this->averageGrade = averageGrade;
}

std::ostream& operator << (std::ostream& out, const Student& st)
{
    out << st.fn << " " << st.name << " " << st.group << " " << st.averageGrade << "\n";
    return out;
}

std::istream& operator >> (std::istream& in, Student& st)
{
    in >> st.fn;

    char buffer[MAX_LEN + 1];
    in >> buffer;
    st.setName(buffer);

    in >> st.group >> st.averageGrade;
    
    return in;
}
