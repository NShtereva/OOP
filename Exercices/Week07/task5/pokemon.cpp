#include "pokemon.hpp"

#include <cassert>
#include <cstring>

Pokemon::Pokemon() : name("-"), type(Type::NORMAL), power(0)
{ }

Pokemon::Pokemon(const char* name, const Type& type, unsigned int power)
    :type(type)
{ 
    assert(name && strlen(name) < MAX_NAME_LEN);
    strcpy(this->name, name);
    
    assert(power >= 10 && power <= 1000);
    this->power = power;
}

bool Pokemon::operator < (const Pokemon& other) const
{
    return this->power < other.power;
}

std::ostream& operator << (std::ostream& out, const Pokemon& p)
{
    out << "name: " << p.name << ", power: " << p.power << std::endl;
    return out;
}
