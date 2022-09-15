#ifndef __STUDENT_HPP
#define __STUDENT_HPP

#include "person.hpp"

class Student : virtual public Person
{
    private:
        int fn;

    public:
        Student(const char* name, const int fn);

        int getFN() const;

        void readDirect(std::istream& in = std::cin);
        virtual void read(std::istream& in = std::cin) override;

        void printDirect(std::ostream& out = std::cout) const;
        virtual void print(std::ostream& out = std::cout) const override;
};

#endif
