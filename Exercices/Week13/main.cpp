#include <iostream>

#include "vehicle.hpp"
#include "car.hpp"
#include "sportCar.hpp"
#include "familyCar.hpp"

int main()
{
    unsigned size = 4;
    Car* array[] = {
                        new SportCar(300, 0, 150000),
                        new SportCar(350, 0, 180000),
                        new FamilyCar(180, 0, 70000),
                        new FamilyCar(200, 0, 90000)
                    };
    
    for(int i = 0; i < size; i++)
    {
        array[i]->print();
        std::cout << std::endl;

        array[i]->startEngine();
        array[i]->startMovement();
        std::cout << "current speed: " << array[i]->getCurrentSpeed() << std::endl;

        array[i]->accelerate(25);
        std::cout << "current speed: " << array[i]->getCurrentSpeed() << std::endl;

        std::cout << "---------------------------------" << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    for(int i = 0; i < size; i++)
    {
        array[i]->print();
        std::cout << std::endl;

        array[i]->stopMovement();
        array[i]->stopEngine();
        std::cout << "current speed: " << array[i]->getCurrentSpeed() << std::endl;
        
        std::cout << "---------------------------------" << std::endl;
    }

    for(int i = 0; i < size; i++)
    {
        delete array[i];
    }
    return 0;
}
