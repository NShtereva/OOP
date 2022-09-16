#ifndef __EVENTMANAGER_HPP
#define __EVENTMANAGER_HPP

#include "event.hpp"

class EventManager
{
    private:
        Event** events;
        size_t size;
        static const size_t CAPACITY = 20;
        
        void deallocate();
        void copy(const EventManager& other);

    public:
        EventManager();
        EventManager(const EventManager& other);
        ~EventManager();

        EventManager& operator = (const EventManager& other);

        bool addEvent(Event* event);
        int onGoingEvents(const Time& t) const;
};

#endif
