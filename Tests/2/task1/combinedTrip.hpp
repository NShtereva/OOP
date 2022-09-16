#ifndef __COMBINEDTRIP_HPP
#define __COMBINEDTRIP_HPP

#include "airTravel.hpp"
#include "carTravel.hpp"

class CombinedTrip : public AirTravel, public CarTravel
{
    private:
        char** destinations;
        size_t numberOfDestinations;
        unsigned int freeTime;

        void deallocateDestinations();
        void copyDestinations(char** destinations);

    public:
        CombinedTrip(const char* flightNumber, unsigned int airTravelDuration, const int* regNumb, double distance, 
                        unsigned int carTravelDuration, char** destinations, const size_t numberOfDestinations, unsigned int freeTime);
        CombinedTrip(const CombinedTrip& other);
        ~CombinedTrip();

        CombinedTrip& operator = (const CombinedTrip& other);

        unsigned int getDuration() const;
        void print() const;
};

#endif
