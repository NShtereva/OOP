#ifndef __MENUITEM_HPP
#define __MENUITEM_HPP

#include <iostream>

class MenuItem
{
    private:
        char* name;
        size_t quantity;
        char* description;
        double price;

        void setName(const char* name);
        void setQuantity(const int quantity);
        void setDescription(const char* description);
        void setPrice(const double price);
    
    public:
        MenuItem(const char* name, const size_t quantity, const char* description, const double price);
        MenuItem(const MenuItem& other);
        virtual ~MenuItem();

        MenuItem& operator = (const MenuItem& other);

        double getPrice() const;
        virtual double getPercentageOfAlcohol() const;
        
        virtual const char* getType() const;
        virtual void getInfo() const; 
};

#endif
