#ifndef __SIMPLEEVENT_HPP
#define __SIMPLEEVENT_HPP

#include <iostream>

#include "event.hpp"

class SimpleEvent : public Event
{
    private:
        static const unsigned int MAX_DURATION = 120;

    public:
        SimpleEvent(const Time& start, const Time& final);

        virtual bool isValidDuration() const override;
        virtual bool isInIntermission(const Time& t) const override;
        virtual SimpleEvent* clone() const override;
};

#endif
