#include "computerShop.hpp"

#include <cstring>

ComputerShop::ComputerShop(const char* name)
    : name(nullptr), computers()
{
    this->setName(name);
}

ComputerShop::ComputerShop(const ComputerShop& other)
    : name(nullptr), computers(other.computers)
{
    this->setName(other.name);
}

ComputerShop::~ComputerShop()
{
    delete[] this->name;
    this->name = nullptr;
}

ComputerShop& ComputerShop::operator = (const ComputerShop& other)
{
    if(this != &other)
    {
        this->setName(other.name);
        this->computers = other.computers;
    }
    return *this;
}

void ComputerShop::setName(const char* name)
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

void ComputerShop::add(const Computer& computer)
{
    bool flag = false;
    int size = computers.getSize();

    for(int i = 0; i < size && !flag; i++)
    {
        if(strcmp(computers[i].getBrand(), computer.getBrand()) == 0)
        {
            computers[i].setQuantity(computers[i].getQuantity() + computer.getQuantity());
            flag = true;
        }
    }

    if(!flag)
    {
        computers.add(computer);
    }
}

void ComputerShop::print() const
{
    std::cout << "name: " << this->name << std::endl;
    std::cout << computers;
}

void ComputerShop::buy(const char* brand, const int money)
{
    int price = -1, index = -1;
    int size = computers.getSize();

    for(int i = 0; i < size && price == -1; i++)
    {
        if(strcmp(computers[i].getBrand(), brand) == 0)
        {
            price = computers[i].getPrice();
            index = i;
        }
    }

    if(price > 0 && money >= price && computers[index].getQuantity() > 0)
    {
        std::cout << "Successful purchase!" << std::endl;
        computers[index].setQuantity(computers[index].getQuantity() - 1);
    }
    else
    {
        std::cout << "The purchase was not successful!" << std::endl;
    }
}

Vector<Computer> ComputerShop::filter(bool (*filter)(const Computer&)) const
{
    Vector<Computer> newVector;

    int size = computers.getSize();
    for(int i = 0; i < size; i++)
    {
        if(computers[i].getQuantity() > 0 && filter(computers[i]))
        {
            newVector.add(computers[i]);
        }
    }

    return newVector;
}
