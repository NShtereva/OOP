#ifndef __FOOD_HPP
#define __FOOD_HPP

#include "menuItem.hpp"

class Food : public MenuItem
{
    private:
        bool isSmall;
        bool suitableForVegans;
    
    public:
        Food(const char* name, const size_t quantity, const char* description, 
                                    const double price, bool isSmall, bool suitableForVegans);
        
        const char* getType() const override;
        void getInfo() const override;
};

#endif
