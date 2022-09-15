#ifndef __FURNITURE_HPP
#define __FURNITURE_HPP

#include <iostream>

class Furniture
{
    private:
        static int counter;
        unsigned int id;
        double height, width, length;
        unsigned int quantity;

    public:
        Furniture(const double height, const double width, const double length, const unsigned int quantity);
        virtual ~Furniture() = default;

        int getId() const;
        double getHeight() const;
        double getWidth() const;
        double getLength() const;
        int getQuantity() const;
        virtual double getPrice() const = 0;

        void decreaseQuantity();

        virtual void print() const;
};

#endif
