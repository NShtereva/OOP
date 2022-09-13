#include <iostream>

#include "menu.hpp"

int main()
{
    Food f1("Salad1", 350, "ala bala", 8, 1, 1);
    Food f2("Salad2", 450, "ala bala", 8.70, 0, 1);
    Food f3("Pasta", 430, "ala bala", 11.49, 0, 0);
    Food f4("Pizza", 370, "ala bala", 12, 1, 0);

    Drink d1("Airqn", 500, "ala bala", 2, ServedIn::JUG);
    Drink d2("Water", 1500, "ala bala", 2.50, ServedIn::BOTTLE);

    Alcohol a1("Vodka", 700, "ala bala", 30, ServedIn::BOTTLE, 39);
    Alcohol a2("Whiskey", 700, "ala bala", 40, ServedIn::BOTTLE, 40);

    Menu::getInstance().add(f1);
    Menu::getInstance().add(f2);
    Menu::getInstance().add(f3);
    Menu::getInstance().add(f4);

    Menu::getInstance().add(d1);
    Menu::getInstance().add(d2);

    Menu::getInstance().add(a1);
    Menu::getInstance().add(a2);

    std::cout << Menu::getInstance().getSize() << std::endl;
    Menu::getInstance().print();

    std::cout << std::endl;
    Menu::getInstance().getTheCheapestProduct().getInfo();

    std::cout << std::endl;
    std::cout << Menu::getInstance().numberOfSoftDrinks() << std::endl;
    
    std::cout << std::endl;
    Menu::getInstance().highestPercentageOfAlcohol();
    return 0;
}