#include "drink.hpp"

Drink::Drink(const char* name, const size_t quantity, const char* description, 
                                                const double price, ServedIn servedIn)
    : MenuItem(name, quantity, description, price), servedIn(servedIn)
{ }

const char* Drink::getType() const
{
    return "drink";
}

void Drink::getInfo() const
{
    std::cout << "type: " << this->getType() << std::endl;
    MenuItem::getInfo();
    std::cout << "served in: ";

    switch(this->servedIn)
    {
        case ServedIn::CUP: std::cout << "cup" << std::endl; break;
        case ServedIn::JUG: std::cout << "jug" << std::endl; break;
        case ServedIn::BOTTLE: std::cout << "bottle" << std::endl; break;
    }
}
