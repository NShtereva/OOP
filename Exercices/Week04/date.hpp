#ifndef __DATE_HPP
#define __DATE_HPP

#include <iostream>

class Date
{
    private:
        uint8_t d;
        uint8_t m;
        uint16_t y;

        bool isLeapYear(unsigned int year) const;

    public:
        Date(unsigned int day, unsigned int month, unsigned int year);

        unsigned int day() const;
        unsigned int month() const;
        unsigned int year() const;

        bool operator == (const Date& rhs) const;
        bool operator < (const Date& rhs) const;
};

#endif
