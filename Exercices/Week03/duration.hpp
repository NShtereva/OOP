#ifndef __DURATION_HPP
#define __DURATION_HPP

#include <iostream>

struct Duration
{
    private:
        size_t min, sec;

    public:
        Duration();
        Duration(int min, int sec);

        size_t getMin() const;
        size_t getSec() const;

        void setMin(int min);
        void setSec(int sec);

        void print() const;
};

#endif
