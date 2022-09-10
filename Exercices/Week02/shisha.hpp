#ifndef __SHISHA_HPP
#define __SHISHA_HPP

#include <iostream>
#include <cstring>

static int hookahReadingIndex = 0;

struct Shisha
{
    private:
        char* brand;
        char* taste;
        double price;

        int getHookahReadingIndex() const;
        void increaseHookahReadingIndex();

    public:
        Shisha();
        Shisha(const char* brand, const char* taste, double price);
        Shisha(const Shisha& other);
        ~Shisha();

        Shisha& operator = (const Shisha& other);

        const char* getBrand() const;
        const char* getTaste() const;
        double getPrice() const;

        void setBrand(const char* brand);
        void setTaste(const char* taste);
        void setPrice(const double& price);

        void read();
        void printWithoutNewLine() const;
        void print() const;
};

#endif
