#include "familyCar.hpp"

FamilyCar::FamilyCar(const double maxSpeed, const double currentSpeed, const double price)
    : Car(maxSpeed, currentSpeed, price)
{ }

void FamilyCar::startEngine()
{
    Car::startEngine();
    std::cout << "The engine of the family car is started. " << std::endl;
}

void FamilyCar::stopEngine()
{
    Car::stopEngine();
    std::cout << "The engine of the family car is stopped. " << std::endl;
}

void FamilyCar::startMovement() noexcept
{
    std::cout << "The family car began to move." << std::endl;
    this->accelerate(50);
}

void FamilyCar::stopMovement()
{
    this->setCurrentSpeed(0);
    std::cout << "The family car stopped moving." << std::endl;
} 

void FamilyCar::print() const
{
    std::cout << "Family car" << std::endl;
    Car::print();
}
