#ifndef __WASHINGMASHINES_HPP
#define __WASHINGMASHINES_HPP

#include <iostream>

#include "WashingMashine.hpp"

class WashingMashines
{
    private:
        WashingMashine* washingMashines;
        size_t N;
        size_t capacity;

        void allocate(const size_t size);
        void deallocate();
        void copy(const WashingMashines& other);

        void setN(const int N);
        void setCapacity(const int capacity);

        void resize();

        void add(const WashingMashine& wm);

        const WashingMashine& operator [] (size_t index) const;
        WashingMashine& operator [] (size_t index);

    public:
        WashingMashines();
        WashingMashines(const WashingMashines& other);
        WashingMashines& operator = (const WashingMashines& other);
        ~WashingMashines();

        void WMWithTheBestCharacteristics() const;

        friend std::istream& operator >> (std::istream& in, WashingMashines& wm);
        friend std::ostream& operator << (std::ostream& out, const WashingMashines& wm);
};

#endif
