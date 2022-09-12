#include <iostream>
#include <fstream>
#include <cstring>

const unsigned MAX_NUMBER_OF_WORDS = 1000;
const unsigned MAX_WORD_LEN = 255;

void replace(const char* fileName, const char* find, const char* replace)
{
    std::ifstream iFile(fileName);
    if(!iFile)
    {
        std::cout << "Problem while opening the file!" << std::endl;
        return;
    }

    char temp[MAX_NUMBER_OF_WORDS][MAX_WORD_LEN], c;
    int index = 0;

    while(!iFile.eof())
    {
        iFile >> temp[index];

        if(strcmp(temp[index], find) == 0)
        {
            strcpy(temp[index], replace);
        }
        index++;
        
        iFile.get(c);
        temp[index][0] = c;
        temp[index][1] = '\0';

        index++;
    }

    iFile.close();

    std::ofstream oFile(fileName, std::ios::trunc);
    if(!oFile)
    {
        std::cout << "Problem while opening the file!" << std::endl;
        return;
    }

    for(int i = 0; i < index; i++)
    {
        oFile << temp[i];
    }

    oFile.close();
}

int main(int argc, char* argv[])
{
    if(argc != 4)
    {
        std::cout << "Incorrect number of arguments!\n";
        return 1;
    }

    replace(argv[1], argv[2], argv[3]);
    return 0;
}
