#include <iostream>

#include "time.hpp"
#include "event.hpp"
#include "simpleEvent.hpp"
#include "eventWithFixedIntermission.hpp"
#include "eventWithIntermission.hpp"
#include "eventManager.hpp"

int main()
{
    Event* events[] = {
                        new SimpleEvent(Time(18, 0), Time(20, 0)),
                        new SimpleEvent(Time(10, 30), Time(11, 45)),
                        new EventWithFixedIntermission(Time(9, 0), Time(10, 0), Time(11, 0)),
                        new EventWithFixedIntermission(Time(21, 30), Time(22, 30), Time(23, 30)),
                        new EventWithIntermission(Time(18, 0), Time(19, 0), Time(19, 30), Time(20, 30)),
                        new EventWithIntermission(Time(10, 30), Time(11, 30), Time(12, 30), Time(13, 30))
                      };
    EventManager em;

    for(int i = 0; i < 6; i++)
    {
        em.addEvent(events[i]);
    }

    std::cout << em.onGoingEvents(Time(10, 30)) << std::endl;
    std::cout << em.onGoingEvents(Time(18, 0)) << std::endl;
    std::cout << em.onGoingEvents(Time(11, 30)) << std::endl;
    std::cout << em.onGoingEvents(Time(22, 45)) << std::endl;
    return 0;
}
