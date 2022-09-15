#ifndef __FAMILYCAR_HPP
#define __FAMILYCAR_HPP

#include "car.hpp"

class FamilyCar : public Car
{
    public:
        FamilyCar(const double maxSpeed, const double currentSpeed, const double price);

        virtual void startEngine() override;
        virtual void stopEngine() override;

        virtual void startMovement() noexcept override;
        virtual void stopMovement() override;

        virtual void print() const override;
};

#endif
