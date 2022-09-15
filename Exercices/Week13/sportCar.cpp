#include "sportCar.hpp"

SportCar::SportCar(const double maxSpeed, const double currentSpeed, const double price)
    : Car(maxSpeed, currentSpeed, price)
{ }

void SportCar::startEngine() 
{
    Car::startEngine();
    std::cout << "The engine of the sport car is started. " << std::endl;
}

void SportCar::stopEngine()
{
    Car::stopEngine();
    std::cout << "The engine of the sport car is stopped. " << std::endl;
}

void SportCar::startMovement() noexcept
{
    std::cout << "The sport car began to move." << std::endl;
    this->accelerate(100);
}

void SportCar::stopMovement() 
{
    this->setCurrentSpeed(0);
    std::cout << "The sport car stopped moving." << std::endl;
} 

void SportCar::print() const
{
    std::cout << "Sport car" << std::endl;
    Car::print();
}
