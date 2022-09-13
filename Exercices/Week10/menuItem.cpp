#include "menuItem.hpp"

#include <cstring>
#include <cassert>

MenuItem::MenuItem(const char* name, const size_t quantity, const char* description, const double price)
    : name(nullptr), description(nullptr)
{
    this->setName(name);
    this->setQuantity(quantity);
    this->setDescription(description);
    this->setPrice(price);
}

MenuItem::MenuItem(const MenuItem& other) 
    : MenuItem(other.name, other.quantity, other.description, other.price)
{ }

MenuItem::~MenuItem()
{
    delete[] this->name;
    this->name = nullptr;

    delete[] this->description;
    this->description = nullptr;
}

MenuItem& MenuItem::operator = (const MenuItem& other)
{
    if(this != &other)
    {
        this->setName(other.name);
        this->setQuantity(other.quantity);
        this->setDescription(other.description);
        this->setPrice(other.price);
    }
    return *this;
}

void MenuItem::setName(const char* name)
{
    if(!name) name = "";

    delete[] this->name;

    this->name = new(std::nothrow) char[strlen(name) + 1];
    if(!this->name)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    strcpy(this->name, name);
}

void MenuItem::setQuantity(const int quantity)
{
    assert(quantity >= 0);
    this->quantity = quantity;
}

void MenuItem::setDescription(const char* description)
{
    if(!description) description = "";

    delete[] this->description;

    this->description = new(std::nothrow) char[strlen(description) + 1];
    if(!this->description)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    strcpy(this->description, description);
}

void MenuItem::setPrice(const double price)
{
    assert(price >= 0);
    this->price = price;
}

double MenuItem::getPrice() const
{
    return this->price;
}

double MenuItem::getPercentageOfAlcohol() const
{
    return 0;
}

const char* MenuItem::getType() const
{
    return "menu item";
}

void MenuItem::getInfo() const
{
    std::cout << "name: "          << this->name        << ", quantity: " << this->quantity 
              << ", description: " << this->description << ", price: "    << this->price
              << std::endl;
}
