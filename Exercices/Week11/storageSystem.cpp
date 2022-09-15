#include "storageSystem.hpp"

#include <cassert>

StorageSystem::StorageSystem()
{
    this->array = new(std::nothrow) Furniture*[INITIAL_CAPACITY];
    if(!this->array)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return;
    }

    this->size = 0;
    this->capacity = INITIAL_CAPACITY;
}

void StorageSystem::resize()
{
    Furniture** newArray = new(std::nothrow) Furniture*[this->capacity * StorageSystem::INCREASE_STEP];
    if(!newArray)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    for(int i = 0; i < this->size; i++)
    {
        newArray[i] = this->array[i]; 
    }

    delete[] this->array;
    
    this->array = newArray;
    newArray = nullptr;

    this->capacity *= StorageSystem::INCREASE_STEP;
}

StorageSystem::~StorageSystem()
{
    for(int i = 0; i < this->size; i++)
    {
        delete this->array[i];
    }
    delete[] this->array;
    this->array = nullptr;
}

StorageSystem& StorageSystem::getInstance()
{
    static StorageSystem object;
    return object; 
}

size_t StorageSystem::getSize() const
{
    return this->size;
}

void StorageSystem::add(const Table& table)
{
    if(this->size + 1 > this->capacity)
    {
        resize();
    }

    this->array[this->size] = new Table(table);
    this->size++;
}

void StorageSystem::add(const Chair& chair)
{
    if(this->size + 1 > this->capacity)
    {
        resize();
    }
    
    this->array[this->size] = new Chair(chair);
    this->size++;
}

void StorageSystem::add(const Bed& bed)
{
    if(this->size + 1 > this->capacity)
    {
        resize();
    }
    
    this->array[this->size] = new Bed(bed);
    this->size++;
}

void StorageSystem::remove(const int id)
{
    for(int i = 0; i < this->size; i++)
    {
        if(this->array[i]->getId() == id)
        {
            if(this->array[i]->getQuantity() - 1 > 0)
            {
                this->array[i]->decreaseQuantity();
            }
            else
            {
                Furniture* save = this->array[i];

                for(int j = i; j < this->size - 1; j++)
                {
                    this->array[j] = this->array[j + 1];
                }
                this->size--;

                delete save;
            }
        }
    }
}

void StorageSystem::print(const int id) const
{
    for(int i = 0; i < this->size; i++)
    {
        if(this->array[i]->getId() == id)
        {
            this->array[i]->print();
        }
    }
}

void StorageSystem::printTheMostExpensiveFurniture() const
{
    assert(this->size > 0);

    int index = 0;
    for(int i = 1; i < this->size; i++)
    {
        if(this->array[i]->getPrice() > this->array[index]->getPrice())
        {
            index = i;
        }
    }
    this->array[index]->print();
}

void StorageSystem::printAll() const
{
    for(int i = 0; i < this->size; i++)
    {
        this->array[i]->print();
        std::cout << "---------------------------------------\n";
    }
}
