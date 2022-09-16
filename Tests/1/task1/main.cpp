#include <iostream>

#include "naturalNumbers.hpp"

int main()
{
    NaturalNumbers n1;
    std::cout << "n1:\n" << n1;

    unsigned int array[] = {1, 3, 8, 0, 9, 6, 3, 2, 4, 3, 0, 7, 5};
    NaturalNumbers n2(array, 13, "n2");
    std::cout << "\nn2:\n" << n2 << std::endl;

    std::ifstream iFile("test.txt");
    if(!iFile)
    {
        std::cout << "Problem while opening the file!" << std::endl;
        return 1;
    }

    iFile >> n1;

    iFile.close();

    std::cout << std::endl;
    std::cout << "n1:\n" << n1.getName() << std::endl;
    n1.printElements();
    std::cout << std::endl;

    NaturalNumbers n3(n1);
    std::cout << "n3:\n" << n3 << std::endl;
    std::cout << std::boolalpha << "n3[0]: " << n3[0] << std::endl;

    n3 = n2;
    std::cout << std::endl;
    std::cout << "n3:\n" << n3 << std::endl;
    std::cout << std::boolalpha << "n3[0]: " << n3[0] << std::endl;
    std::cout << std::endl;

    n3 += n1;
    std::cout << std::endl;
    std::cout << "n3:\n" << n3 << std::endl;

    NaturalNumbers n4 = n1 + n2;
    std::cout << std::endl;
    std::cout << "n4:\n" << n4;
    return 0;
}
