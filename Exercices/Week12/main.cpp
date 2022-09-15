#include <iostream>

#include "assistant.hpp"

int main()
{    
    Assistant a1("Student1", 88888, 0);
    Assistant a2("Student2", 99999, 0);
    Assistant a3("Lecture1", 0, 1500);
    Assistant a4("Lecture1", 0, 1600);

    std::ofstream oFile("test.txt");
    if(!oFile)
    {
        std::cout << "Problem while opening the file!" << std::endl;
        return 1;
    }

    a1.print(oFile);
    a2.print(oFile);
    a3.print(oFile);
    a4.print(oFile);

    oFile.close();

    std::ifstream iFile("test.txt");
    if(!iFile)
    {
        std::cout << "Problem while opening the file!" << std::endl;
        return 1;
    }

    for(int i = 0; i < 4; i++)
    {
        Assistant a;
        a.read(iFile);
        a.print();
        iFile.get();
    }

    iFile.close();

    std::cout << std::endl;

    Assistant a;
    a.read();
    std::cout << std::endl 
              << a.getName() << ", " << a.getFN() << ", " << a.getSalary() 
              << std::endl;
    return 0;
}
