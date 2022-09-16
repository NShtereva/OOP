#include "naturalNumbers.hpp"

#include <cstring>
#include <cassert>

NaturalNumbers::NaturalNumbers() 
    : array(nullptr), capacity(0), size(0), name(nullptr)
{
    this->setName("Empty set");
}

NaturalNumbers::NaturalNumbers(unsigned int* array, const size_t size, const char* name)
    : array(nullptr), size(0), name(nullptr)
{
    this->setName(name);

    this->capacity = size;

    this->array = new(std::nothrow) unsigned int[this->capacity];
    if(!this->array)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return;
    }

    this->getUniqueElements(array, size);
}

NaturalNumbers::NaturalNumbers(const NaturalNumbers& other)
    : array(nullptr), name(nullptr)
{
    this->copy(other);
}

NaturalNumbers::~NaturalNumbers()
{
    this->deallocate();
}

NaturalNumbers& NaturalNumbers::operator = (const NaturalNumbers& other)
{
    if(this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}

void NaturalNumbers::setName(const char* name)
{
    assert(name && strlen(name) < NaturalNumbers::MAX_LEN);

    delete[] this->name;

    this->name = new(std::nothrow) char[strlen(name)];
    if(!this->name)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return;
    }

    strcpy(this->name, name);
}

void NaturalNumbers::sort(unsigned int* array, const size_t size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(array[i] > array[j])
            {
                unsigned int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void NaturalNumbers::getUniqueElements(unsigned int* array, const size_t size)
{
    sort(array, size);
    
    for(int i = 0; i < size; i++)
    {
        this->array[this->size] = array[i];
        this->size++;

        bool flag = false;
        while(i + 1 < size && array[i] == array[i + 1])
        {
            if(!flag)
                std::cout << array[i] << " is a repeating element and will only be added once to the set" << std::endl;
                
            i++;
            flag = true;
        }
    }
}

void NaturalNumbers::copy(const NaturalNumbers& other)
{
    this->capacity = other.capacity;
    this->size = other.size;

    this->array = new(std::nothrow) unsigned int[this->size];
    if(!this->array)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return;
    }

    for(int i = 0; i < this->size; i++)
    {
        this->array[i] = other.array[i];
    }
    
    this->setName(other.name);
}

void NaturalNumbers::deallocate()
{
    delete[] this->array;
    this->array = nullptr;

    delete[] this->name;
    this->name = nullptr;
}

const char* NaturalNumbers::getName() const
{
    return this->name;
}

void NaturalNumbers::printElements() const
{
    for(int i = 0; i < this->size; i++)
    {
        std::cout << this->array[i] << " ";
    }
    std::cout << std::endl;
}

NaturalNumbers& NaturalNumbers::operator += (const NaturalNumbers& other)
{
    if(this->size == 0)
    {
        *this = other;
        return *this;
    }

    if(other.size > 0)
    {
        unsigned int* newArray = new(std::nothrow) unsigned int[this->size + other.size];
        if(!newArray)
        {
            std::cout << "Memory not allocated successfully!" << std::endl;
            return *this;
        }

        int index = 0;

        for(int i = 0; i < this->size; i++)
        {
            newArray[index] = this->array[i];
            index++;
        }

        for(int i = 0; i < other.size; i++)
        {
            newArray[index] = other.array[i];
            index++;
        }

        char* newName = new(std::nothrow) char[strlen("Union of ") + strlen(this->name) + 
                                                    strlen(" and ") + strlen(other.name) + 1];
        if(!newName)
        {
            std::cout << "Memory not allocated successfully!" << std::endl;
            
            delete[] newArray;
            newArray = nullptr;
            
            return *this;
        }

        strcpy(newName, "Union of ");
        strcat(newName, this->name);
        strcat(newName, " and ");
        strcat(newName, other.name);

        NaturalNumbers set(newArray, this->size + other.size, newName);
        *this = set;

        delete[] newName;
        newName = nullptr;

        delete[] newArray;
        newArray = nullptr;
    }

    return *this;
}

NaturalNumbers NaturalNumbers::operator + (const NaturalNumbers& other) const
{
    NaturalNumbers result(*this);
    result += other;
    return result;
}

std::ostream& operator << (std::ostream& out, const NaturalNumbers& set)
{
    out << set.name << std::endl;
    out << set.size << std::endl;

    for(int i = 0; i < set.size; i++)
    {
        out << set.array[i] << " ";
    }
    out << std::endl;

    return out;
}

std::istream& operator >> (std::istream& in, NaturalNumbers& set)
{
    char* newName = new(std::nothrow) char[NaturalNumbers::MAX_LEN];
    if(!newName)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return in;
    }

    in.getline(newName, NaturalNumbers::MAX_LEN);

    size_t size;
    in >> size;

    unsigned int* newArray = new(std::nothrow) unsigned int[size];
    if(!newArray)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;

        delete[] newName;
        newName = nullptr;

        return in;
    }

    for(int i = 0; i < size; i++)
    {
        in >> newArray[i];
    }

    NaturalNumbers result(newArray, size, newName);
    set = result;

    delete[] newName;
    newName = nullptr;

    delete[] newArray;
    newArray = nullptr;

    return in;
}

bool NaturalNumbers::operator [] (int n) const
{
    for(int i = 0; i < this->size; i++)
    {
        if(this->array[i] == n)
            return true;
    }
    return false;
}
