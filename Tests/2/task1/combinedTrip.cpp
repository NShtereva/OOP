#include "combinedTrip.hpp"

#include <cstring>

CombinedTrip::CombinedTrip(const char* flightNumber, unsigned int airTravelDuration, const int* regNumb, double distance, 
                            unsigned int carTravelDuration, char** destinations, const size_t numberOfDestinations, unsigned int freeTime)
    : AirTravel(flightNumber, airTravelDuration), CarTravel(regNumb, distance, carTravelDuration), 
                                        numberOfDestinations(numberOfDestinations), freeTime(freeTime)
{
    this->copyDestinations(destinations);
}

CombinedTrip::CombinedTrip(const CombinedTrip& other) 
    : AirTravel(other), CarTravel(other), numberOfDestinations(other.numberOfDestinations), freeTime(other.freeTime)
{
    this->copyDestinations(other.destinations);
}

CombinedTrip::~CombinedTrip()
{
    this->deallocateDestinations();
}

CombinedTrip& CombinedTrip::operator = (const CombinedTrip& other)
{
    if(this != &other)
    {
        AirTravel::operator=(other); 
        CarTravel::operator=(other);

        this->numberOfDestinations = other.numberOfDestinations;
        this->freeTime = other.freeTime;

        this->deallocateDestinations();
        this->copyDestinations(other.destinations);
    }
    return *this;
}

void CombinedTrip::deallocateDestinations()
{
    for(int i = 0; i < this->numberOfDestinations; i++)
    {
        delete[] this->destinations[i];
    }
    delete[] this->destinations;
    this->destinations = nullptr;
}

void CombinedTrip::copyDestinations(char** destinations)
{
    this->destinations = new(std::nothrow) char*[this->numberOfDestinations];
    if(!this->destinations)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return;
    }

    for(int i = 0; i < this->numberOfDestinations; i++)
    {
        this->destinations[i] = new(std::nothrow) char[strlen(destinations[i]) + 1];
        if(!this->destinations[i])
        {
            std::cout << "Memory not allocated successfully!" << std::endl;
            return;
        }

        strcpy(this->destinations[i], destinations[i]);
    }
}

unsigned int CombinedTrip::getDuration() const
{
    return AirTravel::getDuration() + CarTravel::getDuration() + this->freeTime;
}

void CombinedTrip::print() const
{
    AirTravel::print();
    CarTravel::print();

    std::cout << "--------------" << std::endl;
    std::cout << "Destinations:" << std::endl;
    for(int i = 0; i < this->numberOfDestinations; i++)
    {
        std::cout << this->destinations[i] << std::endl;
    }
    std::cout << "--------------" << std::endl;

    std::cout << "free time: " << this->freeTime << std::endl;
}
