#ifndef __ALCOHOL_HPP
#define __ALCOHOL_HPP

#include "drink.hpp"

class Alcohol : public Drink
{
    private:
        double percentageOfAlcohol;

    public:
        Alcohol(const char* name, const size_t quantity, const char* description, 
                        const double price, ServedIn servedIn, const double percentageOfAlcohol);

        double getPercentageOfAlcohol() const;

        const char* getType() const override;
        void getInfo() const override;
};

#endif
