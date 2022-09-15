#include "furniture.hpp"

#include <cassert>

int Furniture::counter = 0;

Furniture::Furniture(const double height, const double width, const double length, const unsigned int quantity)
    : quantity(quantity)
{
    this->id = counter;
    counter++;

    assert(height > 0);
    this->height = height;

    assert(width > 0);
    this->width = width;

    assert(length > 0);
    this->length = length;
}

int Furniture::getId() const
{
    return this->id;
}

double Furniture::getHeight() const
{
    return this->height;
}

double Furniture::getWidth() const
{
    return this->width;
}

double Furniture::getLength() const
{
    return this->length;
}

int Furniture::getQuantity() const
{
    return this->quantity;
}

void Furniture::decreaseQuantity()
{
    this->quantity--;
}

void Furniture::print() const
{
    std::cout << "height: "   << this->getHeight() << ", width: "    << this->getWidth()
              << ", length: " << this->getLength() << ", quantity: " << this->getQuantity();
}
