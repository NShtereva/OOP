#include "computer.hpp"

#include <cstring>
#include <cassert>

size_t Computer::counter = 0;

Computer::Computer() : Computer("-", "-", 0, 0, 0, 0, 0, 0)
{ }

Computer::Computer(const char* brand, const char* processor, const int video, const int hardDrive,
                    const double weight, const double batteryLife, const double price, const int quantity)
    : brand(nullptr), processor(nullptr)
{
    this->serialNumber = counter;
    counter++;

    this->setBrand(brand);
    this->setProcessor(processor);
    this->setVideo(video);
    this->setHardDrive(hardDrive);
    this->setWeight(weight);
    this->setBatteryLife(batteryLife);
    this->setPrice(price);
    this->setQuantity(quantity);
}

Computer::Computer(const Computer& other)
    : brand(nullptr), processor(nullptr)
{
    this->serialNumber = counter;
    counter++;
    
    this->setBrand(other.brand);
    this->setProcessor(other.processor);
    this->setVideo(other.video);
    this->setHardDrive(other.hardDrive);
    this->setWeight(other.weight);
    this->setBatteryLife(other.batteryLife);
    this->setPrice(other.price);
    this->setQuantity(other.quantity);
}

Computer::~Computer()
{
    delete[] this->brand;
    this->brand = nullptr;

    delete[] this->processor;
    this->processor = nullptr;
}

Computer& Computer::operator = (const Computer& other)
{
    if(this != &other)
    {
        this->setBrand(other.brand);
        this->setProcessor(other.processor);
        this->setVideo(other.video);
        this->setHardDrive(other.hardDrive);
        this->setWeight(other.weight);
        this->setBatteryLife(other.batteryLife);
        this->setPrice(other.price);
        this->setQuantity(other.quantity);
    }
    return *this;
}

size_t Computer::getSerialNumber() const
{
    return this->serialNumber;
}

const char* Computer::getBrand() const
{
    return this->brand;
}

const char* Computer::getProcessor() const
{
    return this->processor;
}

size_t Computer::getVideo() const
{
    return this->video;
}

size_t Computer::getHardDrive() const
{
    return this->hardDrive;    
}

double Computer::getWeight() const
{
    return this->weight;
}

double Computer::getBatteryLife() const
{
    return this->batteryLife;
}

double Computer::getPrice() const
{
    return this->price;
}

size_t Computer::getQuantity() const
{
    return this->quantity;
}

void Computer::setBrand(const char* brand)
{
    if(!brand) brand = "";

    delete[] this->brand;

    this->brand = new(std::nothrow) char[strlen(brand) + 1];
    if(!this->brand)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    strcpy(this->brand, brand);
}

void Computer::setProcessor(const char* processor)
{
    if(!processor) processor = "";

    delete[] this->processor;

    this->processor = new(std::nothrow) char[strlen(processor) + 1];
    if(!this->processor)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    strcpy(this->processor, processor);
}

void Computer::setVideo(const int video)
{
    assert(video >= 0);
    this->video = video;
}

void Computer::setHardDrive(const int hardDrive)
{
    assert(hardDrive >= 0);
    this->hardDrive = hardDrive;
}

void Computer::setWeight(const double weight)
{
    assert(weight >= 0);
    this->weight = weight;
}

void Computer::setBatteryLife(const double batteryLife)
{
    assert(batteryLife >= 0);
    this->batteryLife = batteryLife;
}

void Computer::setPrice(const double price)
{
    assert(price >= 0);
    this->price = price;
}

void Computer::setQuantity(const int quantity)
{
    assert(quantity >= 0);
    this->quantity = quantity;
}

std::istream& operator >> (std::istream& in, Computer& computer)
{
    std::cout << "Enter brand: ";
    in >> computer.brand;

    std::cout << "Enter processor: ";
    in >> computer.processor;

    std::cout << "Enter video: ";
    in >> computer.video;

    std::cout << "Enter hard drive: ";
    in >> computer.hardDrive;

    std::cout << "Enter weight: ";
    in >> computer.weight;

    std::cout << "Enter battery life: ";
    in >> computer.batteryLife;

    std::cout << "Enter price: ";
    in >> computer.price;

    std::cout << "Enter quantity: ";
    in >> computer.quantity;

    return in;
}

std::ostream& operator << (std::ostream& out, const Computer& computer)
{
    out << computer.serialNumber << " " << computer.brand  << " "
        << computer.processor    << " " << computer.video  << " "
        << computer.hardDrive    << " " << computer.weight << " "
        << computer.batteryLife  << " " << computer.price  << " "
        << computer.quantity;

    return out;
}