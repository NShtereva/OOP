#include "vector.hpp"
#include "computer.hpp"
#include "computerShop.hpp"
#include "consultantUtils.hpp"

void testVector()
{
    Vector<int> v1;
    v1.add(1);
    v1.add(2);
    v1.add(3);
    v1.add(4);
    v1.add(5);

    std::cout << "v1:\n" << v1 << std::endl;

    Vector<int> v2(v1);

    v1.remove(1);
    v1.remove(3);

    std::cout << "v1:\n" << v1 << std::endl;
    std::cout << "v2:\n" << v2 << std::endl;

    v1.remove(0);
    v1.remove(1);

    Vector<int> v3;
    v3 = v1;
    std::cout << "v1:\n" << v1 << std::endl;
    std::cout << "v3:\n" << v3 << std::endl;

    v1.remove(0);

    std::cout << "v1:\n" << v1 << std::endl;

    std::cout << v1.empty() << " " << v2.empty() << " " << v3.empty() << std::endl;
    std::cout << "v2[1]: " << v2[1] << std::endl;
    std::cout << "v3 size: " << v3.getSize() << std::endl;
    std::cout << std::endl;

    std::ofstream oFile("vector.txt");
    if(!oFile)
    {
        std::cout << "Problem while opening the file!" << std::endl;
        return;
    }

    oFile << v2;

    oFile.close();

    std::ifstream iFile("vector.txt");
    if(!iFile)
    {
        std::cout << "Problem while opening the file!" << std::endl;
        return;
    }

    iFile >> v1;

    iFile.close();
    
    std::cout << "v1:\n" << v1 << std::endl;
}

void testComputerShop()
{
    Computer computer1("Lenovo", "i7", 3080, 1024, 5, 5, 1800, 1);
    Computer computer2("Lenovo", "i7", 3080, 1024, 5, 5, 1800, 1);
    Computer computer3("Lenovo", "i7", 3080, 1024, 5, 5, 1800, 1);
    Computer computer4("Dell", "i6", 3060, 756, 2, 10, 1200, 1);
    Computer computer5("Dell", "i6", 3060, 756, 2, 10, 1200, 1);
    Computer computer6("Dell", "i6", 3060, 756, 2, 10, 1200, 1);
    Computer computer7("Dell", "i6", 3060, 756, 2, 10, 1200, 1);
    Computer computer8("Acer", "i3", 2000, 200, 3, 5, 900, 1);
    Computer computer9("Asus", "i7", 5000, 2048, 4, 6, 2200, 1);
    
    ComputerShop myShop("Computer shop");
    myShop.add(computer1);
    myShop.add(computer2);
    myShop.add(computer3);
    myShop.add(computer4);
    myShop.add(computer5);
    myShop.add(computer6);
    myShop.add(computer7);
    myShop.add(computer8);
    myShop.add(computer9);

    Vector<Computer> goodForGaming = myShop.filter(ConsultantUtils::isGoodForGaming);

    std::cout << "Good for gaming: " << std::endl;
    std::cout << goodForGaming << std::endl;

    Vector<Computer> goodForTravel = myShop.filter(ConsultantUtils::isGoodForTravel);

    std::cout << "Good for travel: " << std::endl;
    std::cout << goodForTravel << std::endl;
}

int main()
{
    // testVector();
    testComputerShop();
    return 0;
}
