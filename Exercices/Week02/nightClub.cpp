#include "nightClub.hpp"

#include <cassert>
#include <cstring>

NightClub::NightClub() 
    : balloons(nullptr), hoohahs(nullptr), alcohols(nullptr)
{
    balloons = new(std::nothrow) Baloon[CAPACITY];
    if(!balloons)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return;
    }

    hoohahs = new(std::nothrow) Shisha[CAPACITY];
    if(!hoohahs)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return;
    }

    alcohols = new(std::nothrow) Alcohol[CAPACITY];
    if(!alcohols)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return;
    }

    this->setNumberOfBalloons(0);
    this->setNumberOfHookahs(0);
    this->setNumberOfAlcohols(0);
}

NightClub::~NightClub()
{
    delete[] this->balloons;
    this->balloons = nullptr;

    delete[] this->hoohahs;
    this->hoohahs = nullptr;

    delete[] this->alcohols;
    this->alcohols = nullptr;
}

unsigned int NightClub::getNumberOfBalloons() const
{
    return this->numberOfBalloons;
}

unsigned int NightClub::getNumberOfHookahs() const
{
    return this->numberOfHookahs;
}

unsigned int NightClub::getNumberOfAlcohols() const
{
    return this->numberOfAlcohols;
}

void NightClub::setNumberOfBalloons(unsigned int newSize)
{
    assert(newSize >= 0 && newSize < CAPACITY);
    this->numberOfBalloons = newSize;
}

void NightClub::setNumberOfHookahs(unsigned int newSize)
{
    assert(newSize >= 0 && newSize < CAPACITY);
    this->numberOfHookahs = newSize;
}

void NightClub::setNumberOfAlcohols(unsigned int newSize)
{
    assert(newSize >= 0 && newSize < CAPACITY);
    this->numberOfAlcohols = newSize;
    
}

void NightClub::addBalloon()
{
    unsigned int tempIndex = this->getNumberOfBalloons();
    balloons[tempIndex].read();
    this->setNumberOfBalloons(tempIndex + 1);
}

void NightClub::addHoohah()
{
    unsigned int tempIndex = this->getNumberOfHookahs();
    hoohahs[tempIndex].read();
    this->setNumberOfHookahs(tempIndex + 1);
}

void NightClub::addAlcohol()
{
    unsigned int tempIndex = this->getNumberOfAlcohols();
    alcohols[tempIndex].read();
    this->setNumberOfAlcohols(tempIndex + 1);
}

int NightClub::checkBalloonHelper(const char* color) const
{
    unsigned int size = this->getNumberOfBalloons();

    int removalIndex = -1;

    for(int i = 0; i < size && removalIndex == -1; i++)
    {
        if(strcmp(balloons[i].getColor(), color) == 0)
        {
            removalIndex = i;
        }
    }

    return removalIndex;
}

void NightClub::removeBalloon(const char* color)
{
    unsigned int size = this->getNumberOfBalloons();

    int removalIndex = this->checkBalloonHelper(color);

    if(removalIndex != -1)
    {
        balloons[removalIndex].setColor(balloons[size - 1].getColor());
        balloons[removalIndex].setPrice(balloons[size - 1].getPrice());
        this->setNumberOfBalloons(size - 1);
    }
}

void NightClub::checkBalloon(const char* color) const
{
    std::cout << ( 
                  (this->checkBalloonHelper(color) != -1) ? 
                  "Available\n" :
                  "Not available\n" 
                 );
}

int NightClub::checkHoohahHelper(const char* brand, const char* taste) const
{
    unsigned int size = this->getNumberOfHookahs();

    int removalIndex = -1;

    for(int i = 0; i < size && removalIndex == -1; i++)
    {
        if(strcmp(hoohahs[i].getBrand(), brand) == 0 &&
            strcmp(hoohahs[i].getTaste(), taste) == 0)
        {
            removalIndex = i;
        }
    }

    return removalIndex;
}

void NightClub::removeHoohah(const char* brand, const char* taste)
{
    unsigned int size = this->getNumberOfHookahs();

    int removalIndex = this->checkHoohahHelper(brand, taste);

    if(removalIndex != -1)
    {
        hoohahs[removalIndex].setBrand(hoohahs[size - 1].getBrand());
        hoohahs[removalIndex].setTaste(hoohahs[size - 1].getTaste());
        hoohahs[removalIndex].setPrice(hoohahs[size - 1].getPrice());
        this->setNumberOfHookahs(size - 1);
    }
}

void NightClub::checkHoohah(const char* brand, const char* taste) const
{
    std::cout << ( 
                  (this->checkHoohahHelper(brand, taste) != -1) ? 
                  "Available\n" :
                  "Not available\n" 
                 );
}

int NightClub::checkAlcoholHelper(const char* name) const
{
    unsigned int size = this->getNumberOfAlcohols();

    int removalIndex = -1;

    for(int i = 0; i < size && removalIndex == -1; i++)
    {
        if(strcmp(alcohols[i].getName(), name) == 0)
        {
            removalIndex = i;
        }
    }

    return removalIndex;
}

void NightClub::removeAlcohol(const char* name)
{
    unsigned int size = this->getNumberOfAlcohols();

    int removalIndex = this->checkAlcoholHelper(name);

    if(removalIndex != -1)
    {
        alcohols[removalIndex].setName(alcohols[size - 1].getName());
        alcohols[removalIndex].setPrice(alcohols[size - 1].getPrice());
        this->setNumberOfAlcohols(size - 1);
    }
}

void NightClub::checkAlcohol(const char* name) const
{
    std::cout << (
                  (this->checkAlcoholHelper(name) != -1) ? 
                  "Available\n" :
                  "Not available\n"
                 );
}

void NightClub::print() const
{
    unsigned int bSize = this->getNumberOfBalloons();

    std::cout << "\nAvailable balloons:";
    for(int i = 0; i < bSize; i++)
    {
        balloons[i].printWithoutNewLine();
    }

    std::cout << std::endl;

    unsigned int hSize = this->getNumberOfHookahs();

    std::cout << "\nAvailable hoohahs:";
    for(int i = 0; i < hSize; i++)
    {
        hoohahs[i].printWithoutNewLine();
    }

    std::cout << std::endl;

    unsigned int aSize = this->getNumberOfAlcohols();

    std::cout << "\nAvailable alcohols:";
    for(int i = 0; i < aSize; i++)
    {
        alcohols[i].printWithoutNewLine();
    }

    std::cout << std::endl;
}
