#include "car.hpp"

Car::Car(const double maxSpeed, const double currentSpeed, const double price)
{
    this->setMaxSpeed(maxSpeed);
    this->setCurrentSpeed(currentSpeed);
    this->setPrice(price);
}

double Car::getMaxSpeed() const
{
    return this->maxSpeed;
}

double Car::getCurrentSpeed() const
{
    return this->currentSpeed;
}

double Car::getPrice() const
{
    return this->price;
}

void Car::setMaxSpeed(double maxSpeed)
{
    if(maxSpeed <= 0 || maxSpeed > 508)
        throw "Incorrect maximum speed!";
    this->maxSpeed = maxSpeed;
}

void Car::setCurrentSpeed(double currentSpeed)
{
    if(currentSpeed < 0 || currentSpeed > maxSpeed)
        throw "Incorrect current speed!";
    this->currentSpeed = currentSpeed;
}

void Car::setPrice(double price)
{
    if(price <= 0)
        throw "Incorrect price!";
    this->price = price;
}

void Car::startEngine()
{
    this->engine.start();
}

void Car::stopEngine()
{
    this->engine.stop();
}

void Car::accelerate(int time)
{
    this->currentSpeed += time;
    if(this->currentSpeed > this->maxSpeed)
    {
        throw "Exceeded maximum speed!";
    }
}

void Car::print() const
{
    std::cout << "price: "          << this->price                               << ", "
              << "max speed: "      << this->maxSpeed                            << ", "
              << "engine: "         << (this->engine.getState() ? "on" : "off")  << ", "
              << "current speed: "  << this->currentSpeed  << std::endl;
}
