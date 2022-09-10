#ifndef __ALCOHOL_HPP
#define __ALCOHOL_HPP

#include <iostream>
#include <cstring>

static int alcoholReadingIndex = 0;

struct Alcohol
{
    private:
        char* name;
        double price;

        int getAlcoholReadingIndex() const;
        void increaseAlcoholReadingIndex();

    public:
        Alcohol();
        Alcohol(const char* name, double price);
        Alcohol(const Alcohol& other);
        ~Alcohol();

        Alcohol& operator = (const Alcohol& other);

        const char* getName() const;
        double getPrice() const;

        void setName(const char* name);
        void setPrice(const double& price);

        void read();
        void printWithoutNewLine() const;
        void print() const;
};

#endif
