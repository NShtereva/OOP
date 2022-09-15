#ifndef __PERSON_HPP
#define __PERSON_HPP

#include <iostream>
#include <fstream>

class Person
{
    private:
        static const size_t MAX_NAME_LEN = 255;
        char* name;

        void setName(const char* name);
    
    public:
        Person(const char* name);
        Person(const Person& person);
        ~Person();

        Person& operator = (const Person& person);

        const char* getName() const;

        virtual void read(std::istream& in = std::cin);
        virtual void print(std::ostream& out = std::cout) const;
};

#endif
