#ifndef __TIME_HPP
#define __TIME_HPP

#include <iostream>

class Time
{
    private:
        unsigned int hour;
        unsigned int minute;

        void setTime(int hour, int minute);

    public:
        Time();
        Time(const int hour, const int minute);

        Time operator + (const Time& other);
        Time operator + (const int num);
        friend Time operator + (const unsigned int num, const Time& t);

        bool operator > (const Time& other);

        friend std::ostream& operator << (std::ostream& out, const Time& t);
};

#endif
