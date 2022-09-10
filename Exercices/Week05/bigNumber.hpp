#ifndef __BIGNUMBER_HPP
#define __BIGNUMBER_HPP

#include <iostream>

class BigNumber
{
    private:
        char* data;
        size_t capacity;
        size_t size;

        bool isValidNumber(const char* number) const;
        bool isNegativeNumber() const;

        void allocate(const size_t size);

        void setData(const char* data);
        void setCapacity(const int capacity);
        void setSize(const int size);

        void convertToChar(long long int number);

    public:
        BigNumber();
        BigNumber(const char* number);
        BigNumber(long long int number);
        BigNumber(const BigNumber& other);
        ~BigNumber();

        BigNumber& operator = (const BigNumber& other);

        bool operator == (const BigNumber& other) const;
        bool operator != (const BigNumber& other) const;
        bool operator < (const BigNumber& other) const;
        bool operator > (const BigNumber& other) const;

        BigNumber& operator += (const BigNumber& other);
        BigNumber operator + (const BigNumber& other) const;
        BigNumber& operator -= (const BigNumber& other);
        BigNumber operator - (const BigNumber& other) const;
        BigNumber& operator *= (const BigNumber& other);
        BigNumber operator * (const BigNumber& other) const;

        void read();
        void print() const;
};

#endif
