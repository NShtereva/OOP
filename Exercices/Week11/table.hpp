#ifndef __TABLE_HPP
#define __TABLE_HPP

#include "furniture.hpp"

enum class TableType
{
    FOR_LIVINGROOM, FOR_KITCHEN
};

class Table : public Furniture
{
    private:
        TableType type;

    public:
        Table(const double height, const double width, const double length, 
                                        const unsigned int quantity, const TableType& type);

        virtual double getPrice() const override;

        void print() const override;
};

#endif
