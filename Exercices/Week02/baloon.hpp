#ifndef __BALOON_HPP
#define __BALOON_HPP

#include <iostream>
#include <cstring>

static int balloonReadingIndex = 0;

struct Baloon
{
    private:
        char* color;
        double price;

        int getBalloonReadingIndex() const;
        void increaseBalloonReadingIndex();

    public:
        Baloon();
        Baloon(const char* color, double price);
        Baloon(const Baloon& other);
        ~Baloon();

        Baloon& operator = (const Baloon& other);

        double getPrice() const;
        const char* getColor() const;

        void setPrice(const double& price);
        void setColor(const char* color);

        void read();
        void printWithoutNewLine() const;
        void print() const;
};

#endif
