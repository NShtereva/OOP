#ifndef __WASHINGMASHINE_HPP
#define __WASHINGMASHINE_HPP

#include <iostream>

class WashingMashine
{
    private:
        char* maker;
        char* model;
        size_t capacity;
        double electricalConsummation;
        size_t waterConsummation;

        void setMaker(const char* maker);
        void setModel(const char* model);
        void setCapacity(const int capacity);
        void setElectricalConsummation(const double electricalConsummation);
        void setWaterConsummation(const int waterConsummation);

    public:
        WashingMashine();
        WashingMashine(const char* maker, const char* model, const size_t capacity, 
                const double electricalConsummation, const size_t waterConsummation);
        WashingMashine(const WashingMashine& other);
        WashingMashine& operator = (const WashingMashine& other);
        ~WashingMashine();

        bool operator > (const WashingMashine& other);

        friend std::istream& operator >> (std::istream& in, WashingMashine& wm);
        friend std::ostream& operator << (std::ostream& out, const WashingMashine& wm);
};

#endif
