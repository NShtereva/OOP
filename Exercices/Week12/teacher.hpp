#ifndef __TEACHER_HPP
#define __TEACHER_HPP

#include "person.hpp"

class Teacher : virtual public Person
{
    private:
        double salary;

    public:
        Teacher(const char* name, const double salary);

        double getSalary() const;

        void readDirect(std::istream& in = std::cin);
        virtual void read(std::istream& in = std::cin) override;

        void printDirect(std::ostream& out = std::cout) const;
        virtual void print(std::ostream& out = std::cout) const override;
};

#endif
