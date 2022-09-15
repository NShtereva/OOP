#include <iostream>

#include "furniture.hpp"
#include "storageSystem.hpp"

int main()
{
    StorageSystem::getInstance().add(Table(75, 80, 140, 3, TableType::FOR_KITCHEN));
    StorageSystem::getInstance().add(Table(50, 60, 110, 2, TableType::FOR_LIVINGROOM));
    StorageSystem::getInstance().add(Chair(86, 60.5, 66, 4, ChairType::WOODEN));
    StorageSystem::getInstance().add(Chair(90, 61, 60, 4, ChairType::METAL));
    StorageSystem::getInstance().add(Chair(80, 59, 64, 4, ChairType::PLASTIC));
    StorageSystem::getInstance().add(Bed(80, 160, 200, 2));
    StorageSystem::getInstance().add(Bed(75, 94, 200, 4));

    int size = StorageSystem::getInstance().getSize();
    std::cout << size << std::endl;

    for(int i = 0; i < size; i++)
    {
        StorageSystem::getInstance().print(i);
        std::cout << "---------------------------------------\n";
    }

    std::cout << std::endl;
    std::cout << std::endl;
    StorageSystem::getInstance().printTheMostExpensiveFurniture();

    StorageSystem::getInstance().remove(5);
    StorageSystem::getInstance().remove(5);
    StorageSystem::getInstance().remove(0);
    StorageSystem::getInstance().remove(0);
    StorageSystem::getInstance().remove(0);
    StorageSystem::getInstance().remove(6);
    StorageSystem::getInstance().remove(6);
    StorageSystem::getInstance().remove(6);
    StorageSystem::getInstance().remove(6);
    
    std::cout << std::endl;
    std::cout << std::endl;
     std::cout << StorageSystem::getInstance().getSize() << std::endl;
    StorageSystem::getInstance().printAll();
    return 0;
}
