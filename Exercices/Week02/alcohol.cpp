#include "alcohol.hpp"

#include <cassert>

Alcohol::Alcohol() : name(nullptr)
{ 
    this->setName("");
    this->setPrice(0.0);
}

Alcohol::Alcohol(const char* name, double price) : name(nullptr)
{
    this->setName(name);
    this->setPrice(price);
}

Alcohol::Alcohol(const Alcohol& other) : name(nullptr)
{
    this->setName(other.name);
    this->setPrice(other.price);
}

Alcohol::~Alcohol()
{
    delete[] this->name;
    this->name = nullptr;
}

Alcohol& Alcohol::operator = (const Alcohol& other)
{
    if(this != &other)
    {
        this->setName(other.name);
        this->setPrice(other.price);
    }

    return *this;
}

double Alcohol::getPrice() const
{
    return this->price;
}

const char* Alcohol::getName() const
{
    return this->name;
}

void Alcohol::setPrice(const double& price)
{
    assert(price >= 0.0);
    this->price = price;
}

void Alcohol::setName(const char* name)
{
    if(!name) name = "";

    delete[] this->name;

    this->name = new(std::nothrow) char[strlen(name) + 1];
    if(this->name == nullptr)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return;
    }

    strcpy(this->name, name);
}

void Alcohol::read()
{
    double tempPrice;
    char tempName[50];

    std::cout << "Enter name:" << std::endl;

    if(getAlcoholReadingIndex() >= 1) std::cin.get();
    else increaseAlcoholReadingIndex();

    std::cin.getline(tempName, 50);

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

    this->setName(tempName);
    this->setPrice(tempPrice); 
}

void Alcohol::printWithoutNewLine() const
{
    std::cout << "\nname: " 
              << this->getName() 
              << ", price: " 
              << this->getPrice(); 
}

void Alcohol::print() const
{
    printWithoutNewLine();
    std::cout << std::endl; 
}

int Alcohol::getAlcoholReadingIndex() const
{
    return alcoholReadingIndex;
}

void Alcohol::increaseAlcoholReadingIndex()
{
    alcoholReadingIndex = alcoholReadingIndex + 1;
}
