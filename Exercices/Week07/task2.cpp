#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cout << "Incorrect number of arguments!\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if(!file)
    {
        std::cout << "Problem while opening the file!" << std::endl;
        return 1;
    }

    char c;
    int count = 0;
    while(file.get(c))
    {
        count++;
    }

    std::cout << "size: " << count << std::endl;

    file.close();
    return 0;
}
