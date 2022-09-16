#ifndef __EWFI_HPP
#define __EWFI_HPP

#include "event.hpp"

class EventWithFixedIntermission : public Event
{
    private:
        static const unsigned int MAX_DURATION = 240;
        static const unsigned int DURATION_OF_INTERMISSION = 20;
        
        Time beginningOfIntermission;

    public:
        EventWithFixedIntermission(const Time& start, const Time& beginningOfIntermission, const Time& final);
        
        virtual bool isValidDuration() const override;
        virtual bool isInIntermission(const Time& t) const override;
        virtual EventWithFixedIntermission* clone() const override;
};

#endif
