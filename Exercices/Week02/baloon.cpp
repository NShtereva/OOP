#include "baloon.hpp"

#include <cassert>

Baloon::Baloon() : color(nullptr)
{ 
    this->setColor("");
    this->setPrice(0.0);
}

Baloon::Baloon(const char* color, double price) : color(nullptr)
{
    this->setColor(color);
    this->setPrice(price);
}

Baloon::Baloon(const Baloon& other) : color(nullptr)
{
    this->setColor(other.color);
    this->setPrice(other.price);
}

Baloon::~Baloon()
{
    delete[] this->color;
    this->color = nullptr;
}

Baloon& Baloon::operator = (const Baloon& other)
{
    if(this != &other)
    {
        this->setColor(other.color);
        this->setPrice(other.price);
    }

    return *this;
}

double Baloon::getPrice() const
{
    return this->price;
}

const char* Baloon::getColor() const
{
    return this->color;
}

void Baloon::setPrice(const double& price)
{
    assert(price >= 0.0);
    this->price = price;
}

void Baloon::setColor(const char* color)
{
    if(!color) color = "";

    delete[] this->color;

    this->color = new(std::nothrow) char[strlen(color) + 1];
    if(!this->color)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return;
    }

    strcpy(this->color, color);
}

void Baloon::read()
{
    double tempPrice;
    char tempColor[50];

    std::cout << "Enter color:" << std::endl;
    
    if(getBalloonReadingIndex() >= 1) std::cin.get();
    else increaseBalloonReadingIndex();
    
    std::cin.getline(tempColor, 50);

    do
    {
        std::cout << "Enter price:" << std::endl;
        std::cin >> tempPrice;

        while(!std::cin)
        {
            std::cin.clear();
            std::cin.ignore();
            
            std::cin >> tempPrice;
        }
    } while (tempPrice < 0.0);

    this->setColor(tempColor);
    this->setPrice(tempPrice); 
}

void Baloon::printWithoutNewLine() const
{
    std::cout << "\ncolor: " 
              << this->getColor() 
              << ", price: " 
              << this->getPrice(); 
}

void Baloon::print() const
{
    printWithoutNewLine();
    std::cout << std::endl; 
}

int Baloon::getBalloonReadingIndex() const
{
    return balloonReadingIndex;
}

void Baloon::increaseBalloonReadingIndex()
{
    balloonReadingIndex = balloonReadingIndex + 1;
}
