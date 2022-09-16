#include "eventManager.hpp"

EventManager::EventManager()
{
    this->events = new(std::nothrow) Event*[CAPACITY];
    if(!this->events)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    this->size = 0;
}

EventManager::EventManager(const EventManager& other)
{
    this->copy(other);
}

EventManager::~EventManager()
{
    this->deallocate();
}

void EventManager::deallocate()
{
    for(int i = 0; i < this->size; i++)
    {
        delete this->events[i];
    }
    delete[] this->events;
    this->events = nullptr;
}

void EventManager::copy(const EventManager& other)
{
    this->events = new(std::nothrow) Event*[other.CAPACITY];
    if(!this->events)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    for(int i = 0; i < other.size; i++)
    {
        this->events[i] = other.events[i]->clone();
    }

    this->size = other.size;
}

EventManager& EventManager::operator = (const EventManager& other)
{
    if(this != &other)
    {
        this->deallocate();
        this->copy(other);
    }
    return *this;
}

bool EventManager::addEvent(Event* event)
{
    if(this->size + 1 < this->CAPACITY)
    {
        this->events[this->size] = event->clone();
        this->size++;
        
        return true;
    }

    std::cout << "Excess capacity!" << std::endl;
    return false;
}

int EventManager::onGoingEvents(const Time& t) const
{
    int counter = 0;

    for(int i = 0; i < this->size; i++)
    {
        if(this->events[i]->getStart() <= t && t < this->events[i]->getFinal() && !this->events[i]->isInIntermission(t))
        {
            counter++;
        }
    }

    return counter;
}
