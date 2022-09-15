#ifndef __SPORTCAR_HPP
#define __SPORTCAR_HPP

#include "car.hpp"

class SportCar : public Car
{
    public:
        SportCar(const double maxSpeed, const double currentSpeed, const double price);

        virtual void startEngine() override;
        virtual void stopEngine() override;

        virtual void startMovement() noexcept override;
        virtual void stopMovement() override;

        virtual void print() const override;
};

#endif
