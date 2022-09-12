#ifndef __UNIVERSITY_HPP
#define __UNIVERSITY_HPP

#include "student.hpp"

class University
{
    private:
        Student** students;
        size_t size;
        size_t capacity;

        void allocate(const size_t size);
        void copy(const University& other);
        void deallocate();

        void setSize(const int size);
        void setCapacity(const int capacity);

        void resize();

    public:
        University();
        University(const University& other);
        ~University();

        University& operator = (const University& other);

        size_t getSize() const;

        void sort(bool(*cmp)(const Student&, const Student&));

        void filter(bool(*pred)(const Student&));

        University& operator += (const Student& st);
        University& operator -= (int fn);

        const Student& operator [] (size_t i) const;
        Student& operator [] (size_t i);

        friend std::ostream& operator << (std::ostream& out, const University& uni);
        friend std::istream& operator >> (std::istream& in, University& uni);
};

#endif
