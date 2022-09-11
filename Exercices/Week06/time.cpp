#include "time.hpp"

#include <cassert>

Time::Time() : hour(0), minute(0)
{ }

Time::Time(const int hour, const int minute)
{
    assert(hour >= 0 && hour < 24);
    this->hour = hour;

    assert(minute >= 0 && minute < 60);
    this->minute = minute;
}

void Time::setTime(int hour, int minute)
{
    if(minute >= 0 && minute < 60)
    {
        this->minute = minute;
    }
    else if(minute >= 60)
    {
        while(minute > 59)
        {
            minute = minute - 60;
            hour++;
        }

        this->minute = minute;
    }

    if(hour >= 0 && hour <= 23)
    {
        this->hour = hour;
    }
    else if(hour > 23)
    {
        while(hour > 23)
        {
            hour = hour - 24;
        }

        this->hour = hour;
    }
}

Time Time::operator + (const Time& other)
{
    Time result;
    result.setTime(this->hour + other.hour, this->minute + other.minute);
    return result;
}

Time Time::operator + (const int num)
{
    Time result;
    result.setTime(this->hour, this->minute + num);
    return result;
}

Time operator + (const unsigned int num, const Time& t)
{
    Time result;
    result.setTime(t.hour, t.minute + num);
    return result;
}

bool Time::operator > (const Time& other)
{
    return this->hour > other.hour || this->minute > other.minute;
}

std::ostream& operator << (std::ostream& out, const Time& t)
{
    out << t.hour << ":" << t.minute << "\n";
    return out;
}
