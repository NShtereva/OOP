#include "duration.hpp"

Duration::Duration() : min(0), sec(0)
{ }

Duration::Duration(int min, int sec)
{
    this->setMin(min);
    this->setSec(sec);
}

size_t Duration::getMin() const
{
    return this->min;
}

size_t Duration::getSec() const
{
    return this->sec;
}

void Duration::setMin(int min)
{
    if(min >= 0)
        this->min = min;
    else
        this->min = 0;
}

void Duration::setSec(int sec)
{
    if(sec >= 0 && sec < 60)
        this->sec = sec;
    else
        this->sec = 0;
}

void Duration::print() const
{
    std::cout << this->min << ":" << this->sec;
}
