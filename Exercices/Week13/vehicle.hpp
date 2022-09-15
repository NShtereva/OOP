#ifndef __VEHICLE_HPP
#define __VEHICLE_HPP

#include <iostream>

class Vehicle
{
    public:
        virtual ~Vehicle() = default;
        
        virtual void startMovement() noexcept = 0;
        virtual void stopMovement() = 0;
};

#endif
