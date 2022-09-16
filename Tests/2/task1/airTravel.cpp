#include "airTravel.hpp"

#include <cassert>
#include <cstring>

AirTravel::AirTravel(const char* flightNumber, unsigned int duration)
    : flightNumber(nullptr), duration(duration)
{
    this->setFlightNumber(flightNumber);
}

AirTravel::AirTravel(const AirTravel& other)
    : AirTravel(other.flightNumber, other.duration)
{ }

AirTravel::~AirTravel()
{
    delete[] this->flightNumber;
    this->flightNumber = nullptr;
}

AirTravel& AirTravel::operator = (const AirTravel& other)
{
    if(this != &other)
    {
        this->setFlightNumber(other.flightNumber);
        this->duration = other.duration;
    }
    return *this;
}

void AirTravel::setFlightNumber(const char* flightNumber)
{
    assert(flightNumber && strlen(flightNumber) < MAX_LEN);

    delete[] this->flightNumber;

    this->flightNumber = new(std::nothrow) char[strlen(flightNumber) + 1];
    if(!this->flightNumber)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return;
    }

    strcpy(this->flightNumber, flightNumber);
}

unsigned int AirTravel::getDuration() const
{
    return this->duration;
}

void AirTravel::print() const
{
    std::cout << "Air travel, flight number: " << this->flightNumber 
              << ", duration: "                << this->duration 
              << std::endl;
}
