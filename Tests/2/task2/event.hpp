#ifndef __EVENT_HPP
#define __EVENT_HPP

#include <iostream>

#include "time.hpp"

class Event
{
    protected:
        Time start;
        Time final;

    public:
        Event(const Time& start, const Time& final);
        virtual ~Event() = default;

        Time getStart() const;
        Time getFinal() const;

        virtual bool isValidDuration() const = 0;
        virtual bool isInIntermission(const Time& t) const = 0;
        virtual Event* clone() const = 0;
};

#endif
