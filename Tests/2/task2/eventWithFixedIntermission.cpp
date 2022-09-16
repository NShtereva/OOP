#include "eventWithFixedIntermission.hpp"

#include <cassert>

EventWithFixedIntermission::EventWithFixedIntermission(const Time& start, const Time& beginningOfIntermission, const Time& final)
    : Event(start, final)
{
    assert(start < beginningOfIntermission && beginningOfIntermission < final);
    this->beginningOfIntermission = beginningOfIntermission;

    if(!this->isValidDuration())
    {
        std::cout << "Invalid data!" << std::endl;

        this->start = Time();
        this->final = Time();
        this->beginningOfIntermission = Time();
    }
}

bool EventWithFixedIntermission::isValidDuration() const
{
    return this->start.diff(this->final) - this->DURATION_OF_INTERMISSION <= this->MAX_DURATION;
}

bool EventWithFixedIntermission::isInIntermission(const Time& t) const
{
    Time endOfIntermission = this->beginningOfIntermission.add20Min();
    
    return this->beginningOfIntermission <= t && t < endOfIntermission;
}

EventWithFixedIntermission* EventWithFixedIntermission::clone() const
{
    return new EventWithFixedIntermission(*this);
}
