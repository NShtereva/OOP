#include "chair.hpp"

Chair::Chair(const double height, const double width, const double length, 
                                    const unsigned int quantity, const ChairType& type)
    : Furniture(height, width, length, quantity), type(type)
{ }

double Chair::getPrice() const
{
    return this->getHeight() * this->getWidth() * 9;
}

void Chair::print() const
{
    switch(type)
    {
        case ChairType::WOODEN: std::cout << "Wooden chair, "; break;
        case ChairType::METAL: std::cout << "Metal chair, "; break;
        case ChairType::PLASTIC: std::cout << "Plastic chair, "; break;
    }
    
    std::cout << "id: " << this->getId() << ", price: " << this->getPrice() << std::endl;
    Furniture::print();
    std::cout << std::endl;
}
