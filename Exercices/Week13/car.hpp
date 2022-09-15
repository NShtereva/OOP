#ifndef __CAR_HPP
#define __CAR_HPP

#include "vehicle.hpp"
#include "engine.hpp"

class Car : public Vehicle
{
    private:
        double maxSpeed;
        double currentSpeed;
        double price;
        Engine engine;

    public:
        Car(const double maxSpeed, const double currentSpeed, const double price);
        
        double getMaxSpeed() const;
        double getCurrentSpeed() const;
        double getPrice() const;

        void setMaxSpeed(double maxSpeeds);
        void setCurrentSpeed(double currentSpeeds);
        void setPrice(double price);

        virtual void startEngine();
        virtual void stopEngine();

        void accelerate(int time);

        virtual void print() const;
};

#endif
