#ifndef __ASSISTANT_HPP
#define __ASSISTANT_HPP

#include "student.hpp"
#include "teacher.hpp"

#include <fstream>

class Assistant : public Student, public Teacher
{
    public:
        Assistant();
        Assistant(const char* name, const int number, const double salary);

        virtual void read(std::istream& in = std::cin) override;
        virtual void print(std::ostream& out = std::cout) const override;
};

#endif
