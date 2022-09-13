#include "menu.hpp"

#include <cassert>
#include <cstring>

Menu::Menu()
{
    this->menu = new(std::nothrow) MenuItem*[Menu::INITIAL_CAPACITY];
    if(!this->menu)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    this->size = 0;
    this->capacity = Menu::INITIAL_CAPACITY;
}

void Menu::resize()
{
    MenuItem** newMenu = new(std::nothrow) MenuItem*[this->capacity * Menu::INCREASE_STEP];
    if(!newMenu)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    for(int i = 0; i < this->size; i++)
    {
        newMenu[i] = this->menu[i]; 
    }

    delete[] this->menu;
    
    this->menu = newMenu;
    newMenu = nullptr;

    this->capacity *= Menu::INCREASE_STEP;
}

Menu::~Menu()
{
    for(int i = 0; i < this->size; i++)
    {
        delete this->menu[i];
    }
    delete[] this->menu;
}

Menu& Menu::getInstance()
{
    static Menu object;
    return object;
}

size_t Menu::getSize() const
{
    return this->size;
}

void Menu::add(const MenuItem& menuItem)
{
    if(this->size + 1 > this->capacity)
    {
        resize();
    }

    this->menu[this->size] = new MenuItem(menuItem);
    this->size++;
}

void Menu::add(const Food& food)
{
    if(this->size + 1 > this->capacity)
    {
        resize();
    }

    this->menu[this->size] = new Food(food);
    this->size++;
}

void Menu::add(const Drink& drink)
{
    if(this->size + 1 > this->capacity)
    {
        resize();
    }

    this->menu[this->size] = new Drink(drink);
    this->size++;
}

void Menu::add(const Alcohol& alcohol)
{
    if(this->size + 1 > this->capacity)
    {
        resize();
    }

    this->menu[this->size] = new Alcohol(alcohol);
    this->size++;
}

void Menu::print() const
{
    for(int i = 0; i < this->size; i++)
    {
        this->menu[i]->getInfo();
    }
}

const MenuItem& Menu::getTheCheapestProduct() const
{
    assert(this->size > 0);
    
    int index = 0;
    for(int i = 1; i < this->size; i++)
    {
        if(this->menu[i]->getPrice() < this->menu[index]->getPrice())
        {
            index = i;
        }
    }
    return *this->menu[index];
}

unsigned int Menu::numberOfSoftDrinks() const
{
    int counter = 0;
    for(int i = 0; i < this->size; i++)
    {
        if(strcmp(this->menu[i]->getType(), "drink") == 0)
        {
            counter++;
        }
    }
    return counter;
}

void Menu::highestPercentageOfAlcohol() const
{
    int index = -1;
    for(int i = 0; i < this->size; i++)
    {
        if(strcmp(this->menu[i]->getType(), "alcohol") == 0)
        {
            if(index == -1) index = i;
            else
            {
                if(this->menu[index]->getPercentageOfAlcohol() < this->menu[i]->getPercentageOfAlcohol())
                    index = i;
            }
        }
    }
    if(index != -1)
        this->menu[index]->getInfo();
    else 
        std::cout << "There is no added alcohol in the menu!" << std::endl;
}

MenuItem& Menu::operator [] (int index)
{
    assert(index >= 0 && index < this->size);
    return *this->menu[index];
}

const MenuItem& Menu::operator [] (int index) const
{
    assert(index >= 0 && index < this->size);
    return *this->menu[index];
}
