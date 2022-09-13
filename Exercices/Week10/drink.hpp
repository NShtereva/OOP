#ifndef __DRINK_HPP
#define __DRINK_HPP

#include "menuItem.hpp"

enum class ServedIn
{
    CUP, JUG, BOTTLE
};

class Drink : public MenuItem
{
    private:
        ServedIn servedIn;

    public:
        Drink(const char* name, const size_t quantity, const char* description, 
                                                const double price, ServedIn servedIn);
        const char* getType() const override;
        void getInfo() const override;
};

#endif
