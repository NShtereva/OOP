#include "eventWithIntermission.hpp"

#include <cassert>

EventWithIntermission::EventWithIntermission(const Time& start, const Time& beginningOfIntermission, 
                                                        const Time& endOfIntermission, const Time& final)
    : Event(start, final)
{
    assert(start < beginningOfIntermission && beginningOfIntermission < final);
    this->beginningOfIntermission = beginningOfIntermission;
    
    assert(beginningOfIntermission < endOfIntermission && endOfIntermission < final);
    this->endOfIntermission = endOfIntermission;

    if(!this->isValidDuration())
    {
        std::cout << "Invalid data!" << std::endl;

        this->start = Time();
        this->final = Time();
        this->beginningOfIntermission = Time();
        this->endOfIntermission = Time();
    }
}

bool EventWithIntermission::isValidDuration() const
{
    int durationOfIntermission = this->beginningOfIntermission.diff(this->endOfIntermission);

    return this->start.diff(this->final) - durationOfIntermission <= this->MAX_DURATION &&
           (durationOfIntermission >= this->MIN_DURATION_OF_INTERMISSION && durationOfIntermission <= this->MAX_DURATION_OF_INTERMISSION);
}

bool EventWithIntermission::isInIntermission(const Time& t) const
{
    return this->beginningOfIntermission <= t && t < this->endOfIntermission;
}

EventWithIntermission* EventWithIntermission::clone() const
{
    return new EventWithIntermission(*this);
}
