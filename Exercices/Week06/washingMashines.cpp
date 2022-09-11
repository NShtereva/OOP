#include "washingMashines.hpp"

#include <cassert>

const size_t INITIAL_CAPACITY = 2;
const size_t INCREASE_STEP = 2;

WashingMashines::WashingMashines()
{
    this->allocate(INITIAL_CAPACITY);
    this->setN(0);
    this->setCapacity(INITIAL_CAPACITY);
}

WashingMashines::WashingMashines(const WashingMashines& other)
{
    this->copy(other);
}

WashingMashines& WashingMashines::operator = (const WashingMashines& other)
{
    if(this != &other)
    {
        this->deallocate();
        this->copy(other);
    }
    return *this;
}

WashingMashines::~WashingMashines()
{
    this->deallocate();
}

void WashingMashines::allocate(const size_t size)
{
    this->washingMashines = new(std::nothrow) WashingMashine[size];
    if(!this->washingMashines)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return;
    }
}

void WashingMashines::deallocate()
{
    delete[] this->washingMashines;
    this->washingMashines = nullptr;
}

void WashingMashines::copy(const WashingMashines& other)
{
    this->allocate(other.capacity);

    for(int i = 0; i < other.N; i++)
    {
        this->washingMashines[i] = other.washingMashines[i];
    }

    this->setCapacity(other.capacity);
    this->setN(other.N);
}

void WashingMashines::resize()
{
    WashingMashine* newWashingMashines = new(std::nothrow) WashingMashine[this->capacity * INCREASE_STEP];
    if(!newWashingMashines)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return;
    }

    for(int i = 0; i < this->N; i++)
    {
        newWashingMashines[i] = this->washingMashines[i];
    }

    this->setCapacity(this->capacity * INCREASE_STEP);
    this->deallocate();
    this->washingMashines = newWashingMashines;
    newWashingMashines = nullptr;
}

void WashingMashines::setN(const int N)
{
    assert(N >= 0);
    this->N = N;
}

void WashingMashines::setCapacity(const int capacity)
{
    assert(capacity >= INITIAL_CAPACITY);
    this->capacity = capacity;
}

void WashingMashines::add(const WashingMashine& wm)
{
    if(this->N + 1 > this->capacity)
    {
        this->resize();
    }

    this->washingMashines[this->N] = wm;
    this->setN(this->N + 1);
}

const WashingMashine& WashingMashines::operator [] (size_t index) const
{
    assert(index < this->N);
    return this->washingMashines[index];
}

WashingMashine& WashingMashines::operator [] (size_t index)
{
    assert(index < this->N);
    return this->washingMashines[index];
}

void WashingMashines::WMWithTheBestCharacteristics() const
{
    int index = 0;

    for(int i = 1; i < this->N; i++)
    {
        if(this->washingMashines[i] > this->washingMashines[index])
            index = i;
    }

    std::cout << this->washingMashines[index];
}

std::istream& operator >> (std::istream& in, WashingMashines& wm)
{
    int N;
    do
    {
        std::cout << "Enter N:" << std::endl;
        in >> N;

        while(!in)
        {
            in.clear();
            in.ignore();
            
            in >> N;
        }

    } while (N < 0);

    WashingMashine temp;

    for(int i = 0; i < N; i++)
    {
        in >> temp;

        if(!in)
        {
            while(!in)
            {
                in.clear();
                in.ignore();
            }
            
            i--;
        }
        else
        {
            wm.add(temp);
        }
    }

    return in;
}

std::ostream& operator << (std::ostream& out, const WashingMashines& wm)
{
    for(int i = 0; i < wm.N; i++)
    {
        out << wm[i];
    }

    return out;
}
