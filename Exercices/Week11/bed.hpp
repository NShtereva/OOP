#ifndef __BED_HPP
#define __BED_HPP

#include "furniture.hpp"

class Bed : public Furniture
{
    public:
        Bed(const double height, const double width, const double length, const unsigned int quantity);

        virtual double getPrice() const override;

        void print() const override;
};

#endif
