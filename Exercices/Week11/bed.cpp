#include "bed.hpp"

Bed::Bed(const double height, const double width, const double length, const unsigned int quantity)
    : Furniture(height, width, length, quantity)
{ }

double Bed::getPrice() const
{
    return this->getLength() * this->getHeight() * 22;
}

void Bed::print() const
{   
    std::cout << "Bed, id: " << this->getId() << ", price: " << this->getPrice() << std::endl;
    Furniture::print();
    std::cout << std::endl;
}
