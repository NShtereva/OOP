#include <iostream>
#include <fstream>

#include "book.hpp"

int main()
{
    /*
    Book book1("Book1", "Author1", 10000), 
         book2("Book2", "Author2", 999),
         book3("Book3", "Author3", 2000);

    std::ofstream bookOut("library.dat", std::ios::binary);
    if(!bookOut)
    {
        std::cout << "Problem while opening the file" << std::endl;
        return 1;
    }

    bookOut.seekp(0);

    bookOut.write(reinterpret_cast<const char*>(&book1), sizeof(Book));
    bookOut.write(reinterpret_cast<const char*>(&book2), sizeof(Book));
    bookOut.write(reinterpret_cast<const char*>(&book3), sizeof(Book));

    bookOut.close();
    */

    const size_t MAX_SIZE = 100;
    Book bookList[MAX_SIZE];

    std::ifstream iFile("library.dat", std::ios::binary);
    if(!iFile)
    {
        std::cout << "Problem while opening the file!" << std::endl;
        return 1;
    }

    iFile.seekg(0, std::ios::end);
    int endOfFile = iFile.tellg();
    iFile.seekg(0, std::ios::beg);

    int i = 0, 
        size = endOfFile / sizeof(Book);

    while(i < size)
    {
        iFile.read(reinterpret_cast<char*>(&bookList[i]), sizeof(Book));
        i++;
    }

    iFile.close();

    std::ofstream oFile("popular.txt");
    if(!oFile)
    {
        std::cout << "Problem while opening the file!" << std::endl;
        return 1;
    }

    i = 0;
    while(i < size)
    {
        if(bookList[i].getCirculation() >= 1000)
            oFile << bookList[i];
        
        i++;
    }

    oFile.close();
    return 0;
}
