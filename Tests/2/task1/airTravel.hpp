#ifndef __AIRTRAVEL_HPP
#define __AIRTRAVEL_HPP

#include <iostream>

class AirTravel
{
    private:
        static const size_t MAX_LEN = 255;

        char* flightNumber;
        unsigned int duration;

        void setFlightNumber(const char* flightNumber);
    
    public:
        AirTravel(const char* flightNumber, unsigned int duration);
        AirTravel(const AirTravel& other);
        ~AirTravel();

        AirTravel& operator = (const AirTravel& other);

        unsigned int getDuration() const;
        void print() const;
};

#endif
