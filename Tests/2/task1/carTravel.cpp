#include "carTravel.hpp"

#include <cassert>

CarTravel::CarTravel(const int* regNumb, double distance, unsigned int duration)
    : duration(duration)
{
    assert(distance >= 0);
    this->distance = distance;

    for(int i = 0; i < this->regNumbSize; i++)
    {
        assert(regNumb[i] >= 0 && regNumb[i] <= 9);
        this->regNumb[i] = regNumb[i];
    }
}

unsigned int CarTravel::getDuration() const
{
    return this->duration;
}

void CarTravel::print() const
{
    std::cout << "Car travel, vehicle registration number: ";
    for(int i = 0; i < this->regNumbSize; i++)
    {
        std::cout << this->regNumb[i];
    }
    
    std::cout << ", distance: " << this->distance
              << ", duration: " << this->duration
              << std::endl;
}
