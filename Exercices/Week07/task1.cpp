#include <iostream>
#include <fstream>

int main()
{
    std::ifstream file("task1.cpp");
    if(!file)
    {
        std::cout << "Problem while opening the file!" << std::endl;
        return 1;
    }

    char c;
    while(file.get(c))
    {
        std::cout << c;
    }

    file.close();
    return 0;
}
