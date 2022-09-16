#include "time.hpp"

#include <cassert>

Time::Time(unsigned int hour, unsigned int min)
{
    assert(hour < 24 && min < 60);
    this->hour = hour;
    this->min = min;
}

bool Time::operator < (const Time& other) const
{
    return this->hour < other.hour || 
           (this->hour == other.hour && this->min < other.min);
}

bool Time::operator <= (const Time& other) const
{
    return *this < other ||
           (this->hour == other.hour && this->min == other.min);
}

unsigned int Time::diff(const Time& other) const
{   
    assert(*this < other);
    return (other.hour - this->hour) * 60 + (other.min - this->min);
}

const Time Time::add20Min() const 
{
    Time newT(this->hour, this->min);

    newT.min = this->min + 20;
    if(newT.min > 59)
    {
        newT.min -= 60;
        newT.hour++;
    }
    
    return newT;
}
