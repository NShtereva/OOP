#ifndef __POKEMON__HPP
#define __POKEMON__HPP

#include <fstream>

#include "type.hpp"

const unsigned MAX_NAME_LEN = 51;

class Pokemon
{
    private:
        char name[MAX_NAME_LEN];
        Type type;
        unsigned int power;
    
    public:
        Pokemon();
        Pokemon(const char* name, const Type& type, unsigned int power);

        bool operator < (const Pokemon& other) const;
        friend std::ostream& operator << (std::ostream& out, const Pokemon& p);
};

#endif
