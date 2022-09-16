#include "event.hpp"

#include <cassert>
#include <cstring>

Event::Event(const Time& start, const Time& final) 
{
    assert(start < final);

    this->start = start;
    this->final = final;
}

Time Event::getStart() const
{
    return this->start;
}

Time Event::getFinal() const
{
    return this->final;
}
