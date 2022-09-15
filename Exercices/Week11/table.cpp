#include "table.hpp"

Table::Table(const double height, const double width, const double length, 
                                    const unsigned int quantity, const TableType& type)
    : Furniture(height, width, length, quantity), type(type)
{ }

double Table::getPrice() const
{
    return this->getWidth() * this->getLength() * 15;
}

void Table::print() const
{
    if(type == TableType::FOR_LIVINGROOM)
        std::cout << "Living room table, ";
    else if(type == TableType::FOR_KITCHEN)
        std::cout << "Kitchen table, ";
    
    std::cout << "id: " << this->getId() << ", price: " << this->getPrice() << std::endl;
    Furniture::print();
    std::cout << std::endl;
}