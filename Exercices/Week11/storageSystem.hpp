#ifndef __STORAGESYSTEM_HPP
#define __STORAGESYSTEM_HPP

#include "table.hpp"
#include "chair.hpp"
#include "bed.hpp"
#include "furniture.hpp"

#include <iostream>

class StorageSystem
{
    private:
        static const size_t INITIAL_CAPACITY = 2;
        static const size_t INCREASE_STEP = 2;

        Furniture** array;
        size_t size;
        size_t capacity;

        StorageSystem();

        void resize();

    public:
        StorageSystem(const StorageSystem& other) = delete;
        StorageSystem& operator = (const StorageSystem& other) = delete;
        ~StorageSystem();

        static StorageSystem& getInstance();

        size_t getSize() const;

        void add(const Table& table);
        void add(const Chair& chair);
        void add(const Bed& bed);

        void remove(const int id);

        void print(const int id) const;
        void printTheMostExpensiveFurniture() const;
        void printAll() const;
};

#endif
