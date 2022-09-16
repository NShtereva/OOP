#ifndef __CARTRAVEL_HPP
#define __CARTRAVEL_HPP

#include <iostream>

class CarTravel
{
    private:
        static const size_t regNumbSize = 4;

        int regNumb[regNumbSize];
        double distance;
        unsigned int duration;
    
    public:
        CarTravel(const int* regNumb, double distance, unsigned int duration);
        
        unsigned int getDuration() const;
        void print() const;
};

#endif
