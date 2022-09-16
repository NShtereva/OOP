#include "simpleEvent.hpp"

#include <cassert>
#include <cstring>

SimpleEvent::SimpleEvent(const Time& start, const Time& final) 
    : Event(start, final)
{
    if(!this->isValidDuration())
    {
        std::cout << "Invalid data!" << std::endl;

        this->start = Time();
        this->final = Time();
    }
}

bool SimpleEvent::isValidDuration() const
{
    return this->start.diff(this->final) <= MAX_DURATION;
}

bool SimpleEvent::isInIntermission(const Time& t) const
{
    return false;
}

SimpleEvent* SimpleEvent::clone() const
{
    return new SimpleEvent(*this);
}
