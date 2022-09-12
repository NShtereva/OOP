#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        std::cout << "Incorrect number of arguments!\n";
        return 1;
    }

    std::ifstream file(argv[1], std::ios::binary);
    if(!file)
    {
        std::cout << "Problem while opening the file!" << std::endl;
        return 1;
    }

    file.seekg(0, std::ios::end);
    int size = file.tellg();

    std::cout << "size: " << size << std::endl;

    file.close();
    return 0;
}
