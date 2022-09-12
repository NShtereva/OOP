#ifndef __STUDENT_HPP
#define __STUDENT_HPP

#include <iostream>
#include <fstream>

class Student
{
    private:
        char* name;
        unsigned int fn;
        unsigned int group;
        double averageGrade;

    public:
        Student();
        Student(const char* name, const int fn, const int group, const double averageGrade);
        Student(const Student& other);
        ~Student();

        Student& operator = (const Student& other);
        
        bool operator < (const Student& other) const;
        bool operator == (const Student& other) const;

        const char* getName() const;
        unsigned getFN() const;
        unsigned getGroup() const;
        double getAverageGrade() const;

        void setName(const char* name);
        void setFN(const int fn);
        void setGroup(const int group);
        void setAverageGrade(const double averageGrade);

        friend std::ostream& operator << (std::ostream& out, const Student& st);
        friend std::istream& operator >> (std::istream& in, Student& st);
};      

#endif
