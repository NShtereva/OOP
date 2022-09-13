#ifndef __MENU_HPP
#define __MENU_HPP

#include "menuItem.hpp"
#include "food.hpp"
#include "drink.hpp"
#include "alcohol.hpp"

class Menu
{
    private:
        static const size_t INITIAL_CAPACITY = 2;
        static const size_t INCREASE_STEP = 2;

        MenuItem** menu;
        size_t size;
        size_t capacity;

        Menu();

        void resize();

    public:
        Menu(const Menu& other) = delete;
        Menu& operator = (const Menu& other) = delete;
        ~Menu();

        static Menu& getInstance();

        size_t getSize() const;

        void add(const MenuItem& menuItem);
        void add(const Food& food);
        void add(const Drink& drink);
        void add(const Alcohol& alcohol);

        void print() const;

        const MenuItem& getTheCheapestProduct() const;
        unsigned int numberOfSoftDrinks() const;
        void highestPercentageOfAlcohol() const;

        MenuItem& operator [] (int index);
        const MenuItem& operator [] (int index) const;
};

#endif
