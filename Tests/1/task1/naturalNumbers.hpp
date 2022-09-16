#ifndef __NATURALNUMBERS_HPP
#define __NATURALNUMBERS_HPP

#include <iostream>
#include <fstream>

class NaturalNumbers
{
    private:
        unsigned int* array;
        size_t capacity;
        size_t size;

        char* name;
        static const unsigned int MAX_LEN = 256;

        void setName(const char* name);

        static void sort(unsigned int* array, const size_t size);
        void getUniqueElements(unsigned int* array, const size_t size);

        void copy(const NaturalNumbers& other);
        void deallocate();

    public:
        NaturalNumbers();
        NaturalNumbers(unsigned int* array, const size_t size, const char* name);
        NaturalNumbers(const NaturalNumbers& other);
        ~NaturalNumbers();

        NaturalNumbers& operator = (const NaturalNumbers& other);

        const char* getName() const;
        void printElements() const;

        NaturalNumbers& operator += (const NaturalNumbers& other);
        NaturalNumbers operator + (const NaturalNumbers& other) const;

        friend std::ostream& operator << (std::ostream& out, const NaturalNumbers& set);
        friend std::istream& operator >> (std::istream& in, NaturalNumbers& set);
        
        bool operator [] (int n) const;
};

#endif
