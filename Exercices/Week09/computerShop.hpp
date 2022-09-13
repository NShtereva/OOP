#ifndef __COMPUTERSHOP_HPP
#define __COMPUTERSHOP_HPP

#include "vector.hpp"
#include "computer.hpp"

class ComputerShop
{
    private:
        char* name;
        Vector<Computer> computers;

        void setName(const char* name);

    public:
        ComputerShop(const char* name);
        ComputerShop(const ComputerShop& other);
        ~ComputerShop();

        ComputerShop& operator = (const ComputerShop& other);

        void add(const Computer& computer);
        void print() const;
        void buy(const char* brand, const int money);

        Vector<Computer> filter(bool (*filter)(const Computer&)) const;
};

#endif
