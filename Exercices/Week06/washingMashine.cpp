#include "washingMashine.hpp"

#include <cstring>
#include <cassert>

WashingMashine::WashingMashine() : maker(nullptr), model(nullptr)
{
    this->setMaker("");
    this->setModel("");
    this->setCapacity(0);
    this->setElectricalConsummation(0);
    this->setWaterConsummation(0);
}

WashingMashine::WashingMashine(const char* maker, const char* model, const size_t capacity, 
                                const double electricalConsummation, const size_t waterConsummation)
    : maker(nullptr), model(nullptr)
{
    this->setMaker(maker);
    this->setModel(model);
    this->setCapacity(capacity);
    this->setElectricalConsummation(electricalConsummation);
    this->setWaterConsummation(waterConsummation);
}

WashingMashine::WashingMashine(const WashingMashine& other)
    : maker(nullptr), model(nullptr)
{
    this->setMaker(other.maker);
    this->setModel(other.model);
    this->setCapacity(other.capacity);
    this->setElectricalConsummation(other.electricalConsummation);
    this->setWaterConsummation(other.waterConsummation);
}

WashingMashine& WashingMashine::operator = (const WashingMashine& other)
{
    if(this != &other)
    {
        this->setMaker(other.maker);
        this->setModel(other.model);
        this->setCapacity(other.capacity);
        this->setElectricalConsummation(other.electricalConsummation);
        this->setWaterConsummation(other.waterConsummation);
    }
    return *this;
}

WashingMashine::~WashingMashine()
{
    delete[] this->maker;
    this->maker = nullptr;

    delete[] this->model;
    this->model = nullptr;
}

bool WashingMashine::operator > (const WashingMashine& other)
{
    return this->electricalConsummation < other.electricalConsummation ||
           this->waterConsummation < other.waterConsummation ||
           this->capacity > other.capacity;
}

void WashingMashine::setMaker(const char* maker)
{
    if(!maker) maker = "";

    delete[] this->maker;

    this->maker = new(std::nothrow) char[strlen(maker) + 1];
    if(!this->maker)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    strcpy(this->maker, maker);
}

void WashingMashine::setModel(const char* model)
{
    if(!model) model = "";

    delete[] this->model;

    this->model = new(std::nothrow) char[strlen(model) + 1];
    if(!this->model)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    strcpy(this->model, model);
}

void WashingMashine::setCapacity(const int capacity)
{
    assert(capacity >= 0 && capacity <= 10);
    this->capacity = capacity;
}

void WashingMashine::setElectricalConsummation(const double electricalConsummation)
{
    assert(electricalConsummation >= 0);
    this->electricalConsummation = electricalConsummation;
}

void WashingMashine::setWaterConsummation(const int waterConsummation)
{
    assert(waterConsummation >= 0 && waterConsummation <= 80);
    this->waterConsummation = waterConsummation;
}

std::istream& operator >> (std::istream& in, WashingMashine& wm)
{
    char maker[255];
    std::cout << "\nEnter maker:" << std::endl;
    in.get();
    in.getline(maker, 255);

    char model[255];
    std::cout << "Enter model:" << std::endl;
    in.getline(model, 255);

    int capacity;
    do
    {
        std::cout << "Enter capacity:" << std::endl;
        in >> capacity;

        while(!in)
        {
            in.clear();
            in.ignore();
            
            in >> capacity;
        }

    } while (capacity < 0);

    double electricalConsummation;
    do
    {
        std::cout << "Enter electrical consummation:" << std::endl;
        in >> electricalConsummation;

        while(!in)
        {
            in.clear();
            in.ignore();

            in >> electricalConsummation;
        }

    } while (electricalConsummation < 0);
    

    int waterConsummation;
    do
    {
        std::cout << "Enter water consummation:" << std::endl;
        in >> waterConsummation;

        while(!in)
        {
            in.clear();
            in.ignore();

            in >> waterConsummation;
        }

    } while (waterConsummation < 0);

    if(in)
    {
        wm.setMaker(maker);
        wm.setModel(model);
        wm.setCapacity(capacity);
        wm.setElectricalConsummation(electricalConsummation);
        wm.setWaterConsummation(waterConsummation);
    }
    else
    {
        while(!in)
        {
            in.clear();
            in.ignore();
        }
    }

    return in;
}

std::ostream& operator << (std::ostream& out, const WashingMashine& wm)
{
    out << "maker: " << wm.maker 
        << ", model: " << wm.model 
        << ", capacity: " << wm.capacity 
        << ", electrical consummation: " << wm.electricalConsummation
        << ", waterConsummation: " << wm.waterConsummation
        << std::endl;

    return out;
}
