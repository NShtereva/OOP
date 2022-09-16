#ifndef __EWI_HPP
#define __EWI_HPP

#include "event.hpp"

class EventWithIntermission : public Event
{
    private:
        static const unsigned int MAX_DURATION = 360;
        static const unsigned int MIN_DURATION_OF_INTERMISSION = 30;
        static const unsigned int MAX_DURATION_OF_INTERMISSION = 60;

        Time beginningOfIntermission;
        Time endOfIntermission;

    public:
        EventWithIntermission(const Time& start, const Time& beginningOfIntermission, 
                                            const Time& endOfIntermission, const Time& final);
        
        virtual bool isValidDuration() const override;
        virtual bool isInIntermission(const Time& t) const override;
        virtual EventWithIntermission* clone() const override;
};

#endif
