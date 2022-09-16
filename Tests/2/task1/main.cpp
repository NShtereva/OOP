#include <iostream>
#include <cstring>

#include "combinedTrip.hpp"

int main()
{
    int regNumb[4] = {9, 3, 1, 2};

    char** destinations = new(std::nothrow) char*[4];
    if(!destinations)
    {
        std::cout << "Memory not allocated successfully!" << std::endl;
        return 1;
    }

    for(int i = 0; i < 4; i++)
    {
        destinations[i] = new(std::nothrow) char[255];
        if(!destinations[i])
        {
            std::cout << "Memory not allocated successfully!" << std::endl;
            return 1;
        }
    }

    strcpy(destinations[0], "Destination1");
    strcpy(destinations[1], "Destination2");
    strcpy(destinations[2], "Destination3");
    strcpy(destinations[3], "Destination4");

    CombinedTrip combinedTrip("A9513", 90, regNumb, 60, 75, destinations, 4, 30);
    combinedTrip.print();

    std::cout << std::endl;
    std::cout << "Full duration: " << combinedTrip.getDuration() << std::endl;

    for(int i = 0; i < 4; i++)
    {
        delete[] destinations[i];
    }
    delete[] destinations;
    destinations = nullptr;
    return 0;
}