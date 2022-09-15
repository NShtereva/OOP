#ifndef __CHAIR_HPP
#define __CHAIR_HPP

#include "furniture.hpp"

enum class ChairType
{
    WOODEN, METAL, PLASTIC
};

class Chair : public Furniture
{
    private:
        ChairType type;
    
    public:
        Chair(const double height, const double width, const double length, 
                                    const unsigned int quantity, const ChairType& type);

        virtual double getPrice() const override;

        void print() const override;
};

#endif
