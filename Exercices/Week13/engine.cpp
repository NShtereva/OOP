#include "engine.hpp"

Engine::Engine() : state(false)
{ }

bool Engine::getState() const
{
    return this->state;
}

void Engine::start()
{
    this->state = true;
}

void Engine::stop()
{
    this->state = false;
}
