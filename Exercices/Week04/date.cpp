#include "date.hpp"

#include <cassert>

Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
    assert(month <= 12);

    if(this->isLeapYear(year) && month == 2)
    {
        assert(day <= 29);
    }
    else if(!this->isLeapYear(year) && month == 2)
    {
        assert(day <= 28);
    }

    if(month == 1 || month == 3 || month == 5 || month == 7 || 
            month == 8 || month == 10 || month == 12)
    {
        assert(day <= 31);
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11)
    {
        assert(day <= 30);
    }
    
    this->d = day;
    this->m = month;
    this->y = year;
}

bool Date::isLeapYear(unsigned int year) const
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

unsigned int Date::day() const
{
    return this->d;
}

unsigned int Date::month() const
{
    return this->m;
}

unsigned int Date::year() const
{
    return this->y;
}

bool Date::operator == (const Date& rhs) const
{
    return this->d == rhs.d && 
           this->m == rhs.m && 
           this->y == rhs.y;
}

bool Date::operator < (const Date& rhs) const
{
    return this->y < rhs.y ||
           (this->y == rhs.y && this->m < rhs.m) ||
           (this->y == rhs.y && this->m == rhs.m && this->d < rhs.d);
}
