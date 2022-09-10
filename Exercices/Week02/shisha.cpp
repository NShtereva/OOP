#include "shisha.hpp"

#include <cassert>

Shisha::Shisha() : brand(nullptr), taste(nullptr)
{
    this->setBrand("");
    this->setTaste("");
    this->setPrice(0.0);
}

Shisha::Shisha(const char* brand, const char* taste, double price) 
    : brand(nullptr), taste(nullptr)
{
    this->setBrand(brand);
    this->setTaste(taste);
    this->setPrice(price);
}

Shisha::Shisha(const Shisha& other) 
    : brand(nullptr), taste(nullptr)
{
    this->setBrand(brand);
    this->setTaste(taste);
    this->setPrice(price);
}

Shisha::~Shisha()
{
    delete[] this->brand;
    this->brand = nullptr;

    delete[] this->taste;
    this->taste = nullptr;
}

Shisha& Shisha::operator = (const Shisha& other)
{
    if(this != &other)
    {
        this->setBrand(other.brand);
        this->setTaste(other.taste);
        this->setPrice(other.price);
    }

    return *this;
}

const char* Shisha::getBrand() const
{
    return this->brand;
}

const char* Shisha::getTaste() const
{
    return this->taste;
}

double Shisha::getPrice() const
{
    return this->price;
}

void Shisha::setBrand(const char* brand)
{
    if(!brand) brand = "";

    delete[] this->brand;
    
    this->brand = new(std::nothrow) char[strlen(brand) + 1];
    if(this->brand == nullptr)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return;
    }

    strcpy(this->brand, brand);
}

void Shisha::setTaste(const char* taste)
{
    if(!taste) taste = "";

    delete[] this->taste;
    
    this->taste = new(std::nothrow) char[strlen(taste) + 1];
    if(this->taste == nullptr)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return;
    }

    strcpy(this->taste, taste);
}

void Shisha::setPrice(const double& price)
{
    assert(price >= 0.0);
    this->price = price;
}

void Shisha::read()
{
    char tempBrand[50], tempTaste[50];
    double tempPrice;

    std::cout << "Enter brand:" << std::endl;

    if(getHookahReadingIndex() >= 1) std::cin.get();
    else increaseHookahReadingIndex();

    std::cin.getline(tempBrand, 50);

    std::cout << "Enter taste:" << std::endl;
    std::cin.getline(tempTaste, 50);

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

    this->setBrand(tempBrand);
    this->setTaste(tempTaste);
    this->setPrice(tempPrice);
}

void Shisha::printWithoutNewLine() const
{
    std::cout << "\nbrand: " 
              << this->getBrand()
              << ", taste: "
              << this->getTaste()
              << ", price: "
              << this->getPrice();
}

void Shisha::print() const
{
    printWithoutNewLine();
    std::cout << std::endl;
}

int Shisha::getHookahReadingIndex() const
{
    return hookahReadingIndex;
}

void Shisha::increaseHookahReadingIndex()
{
    hookahReadingIndex = hookahReadingIndex + 1;
}
