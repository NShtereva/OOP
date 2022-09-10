#include "bigNumber.hpp"
#include "bigNumberHelper.hpp"

#include <cstring>
#include <cassert>

const size_t INITIAL_CAPACITY = 2;
const size_t INCREASE_STEP = 2;

BigNumber::BigNumber() : data(nullptr)
{
    this->setData("0");
    this->setCapacity(INITIAL_CAPACITY);
    this->setSize(1);
}

BigNumber::BigNumber(const char* number) : data(nullptr)
{
    if(isValidNumber(number))
    {
        this->setData(number);
        this->setCapacity(strlen(number) * INCREASE_STEP);
        this->setSize(strlen(number));
    }
    else
    {
        this->setData("0");
        this->setCapacity(INITIAL_CAPACITY);
        this->setSize(1);
    }
}

BigNumber::BigNumber(long long int number) : data(nullptr)
{
    int len = (number > 0) ? numberOfDigits(number) : numberOfDigits(-number) + 1;
    this->allocate(len * INCREASE_STEP);

    this->setCapacity(len * INCREASE_STEP);
    this->setSize(len);

    this->convertToChar(number);
}

BigNumber::BigNumber(const BigNumber& other) : data(nullptr)
{
    this->setData(other.data);
    this->setCapacity(other.capacity);
    this->setSize(other.size);
}

BigNumber::~BigNumber()
{
    delete[] this->data;
    this->data = nullptr;
}

BigNumber& BigNumber::operator = (const BigNumber& other)
{
    if(this != &other)
    {
        this->setData(other.data);
        this->setCapacity(other.capacity);
        this->setSize(other.size);
    }

    return *this;
}

bool BigNumber::isValidNumber(const char* number) const
{
    if(strcmp(number, "0") == 0) 
        return true;

    if (!(number[0] >= '1' && number[0] <= '9') && number[0] != '-')
        return false;

    if(number[0] == '-' && !(number[1] >= '1' && number[1] <= '9'))
        return false;

    for (int i = 1; i < strlen(number); i++)
    {
        if (!(number[i] >= '0' && number[i] <= '9'))
        {
            return false;
        }
    }

    return true;
}

bool BigNumber::isNegativeNumber() const
{
    return this->data[0] == '-';
}

void BigNumber::allocate(const size_t size)
{
    this->data = new(std::nothrow) char[size];
    if(!this->data)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }
}

void BigNumber::setData(const char* data)
{
    if(!data) data = "";

    delete[] this->data;

    this->data = new(std::nothrow) char[strlen(data) + 1];
    if(!this->data)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    strcpy(this->data, data);
}

void BigNumber::setCapacity(const int capacity)
{
    assert(capacity >= INITIAL_CAPACITY);
    this->capacity = capacity;
}

void BigNumber::setSize(const int size)
{
    assert(size >= 0);
    this->size = size;
}    

void BigNumber::convertToChar(long long int number)
{
    long long int reverseNum;
    int index = 0;

    if(number < 0)
    {
        reverseNum = reverse(-number);

        this->data[index] = '-';
        index++;

        this->setSize(this->size + 1);
    }
    else
    {
        reverseNum = reverse(number);
    }

    while(reverseNum != 0)
    {
        int temp = reverseNum % 10;

        this->data[index] = temp + '0';
        index++;

        reverseNum = reverseNum / 10;

        this->setSize(this->size + 1);
    }

    this->data[index] = '\0';
    index++;
    this->setSize(this->size + 1);
}

bool BigNumber::operator == (const BigNumber& other) const
{
    return strcmp(this->data, other.data) == 0;
}

bool BigNumber::operator != (const BigNumber& other) const
{
    return !(*this == other);
}

bool BigNumber::operator < (const BigNumber& other) const
{
    if(this->isNegativeNumber() && !other.isNegativeNumber()) 
    {
        return true;
    }
    else if(!this->isNegativeNumber() && other.isNegativeNumber()) 
    {
        return false;
    }
    else if(!this->isNegativeNumber() && !other.isNegativeNumber())
    {
        if(this->size < other.size)
        {
            return true;
        }
        else if(this->size > other.size)
        {
            return false;
        }
        else
        {
            return lessThan(this->data, other.data);
        }
    }
    else // this->isNegativeNumber() && other.isNegativeNumber()
    {
        if(this->size < other.size)
        {
            return false;
        }
        else if(this->size > other.size)
        {
            return true;
        }
        else
        {
            char* num1 = removeMinus(this->data);
            char* num2 = removeMinus(other.data);

            bool flag = !lessThan(num1, num2);

            delete[] num1; num1 = nullptr;
            delete[] num2; num2 = nullptr;

            return flag;
        }
    }
}

bool BigNumber::operator > (const BigNumber& other) const
{
    return *this != other && !(*this < other);
}

BigNumber& BigNumber::operator += (const BigNumber& other)
{
    *this = *this + other;
    return *this;
}

BigNumber BigNumber::operator + (const BigNumber& other) const
{
    if(!this->isNegativeNumber() && !other.isNegativeNumber())
    {
        char* temp = (this->size >= other.size) ? 
                     sumOfTwoPositiveNumbers(this->data, other.data) : 
                     sumOfTwoPositiveNumbers(other.data, this->data);

        if(!temp) return BigNumber();
        
        BigNumber result(temp);
        delete[] temp; temp = nullptr;
        return result;
    }
    else if(this->isNegativeNumber() && other.isNegativeNumber())
    {
        char* num1 = removeMinus(this->data);
        char* num2 = removeMinus(other.data);

        char* temp = (strlen(num1) >= strlen(num2)) ? 
                     sumOfTwoPositiveNumbers(num1, num2) : 
                     sumOfTwoPositiveNumbers(num2, num1);

        delete[] num1; num1 = nullptr;
        delete[] num2; num2 = nullptr;

        if(!temp) return BigNumber();
        
        addASymbolAtTheBeginning(temp, '-');

        BigNumber result(temp);
        delete[] temp; temp = nullptr;
        return result;
    }
    else if(!this->isNegativeNumber() && other.isNegativeNumber())
    {
        char* num2 = removeMinus(other.data);
    
        BigNumber result = *this - num2;
        delete[] num2; num2 = nullptr;
        return result;
    }
    else // this->isNegativeNumber() && !other.isNegativeNumber()
    {
        char* num1 = removeMinus(this->data);
    
        BigNumber result = other - num1;
        delete[] num1; num1 = nullptr;
        return result;
    }
}

BigNumber& BigNumber::operator -= (const BigNumber& other)
{
    *this = *this - other;
    return *this;
}

BigNumber BigNumber::operator - (const BigNumber& other) const
{
    if(!this->isNegativeNumber() && !other.isNegativeNumber())
    {
        char* temp = subtractionOfTwoPositiveNumbers(this->data, other.data);
        if(!temp) return BigNumber();
        
        BigNumber result(temp);
        delete[] temp; temp = nullptr;
        return result;
    }
    else if(this->isNegativeNumber() && other.isNegativeNumber())
    {
        char* num1 = removeMinus(this->data);
        char* num2 = removeMinus(other.data);

        char* temp = subtractionOfTwoPositiveNumbers(num2, num1);

        delete[] num1; num1 = nullptr;
        delete[] num2; num2 = nullptr;

        if(!temp) return BigNumber();

        BigNumber result(temp);
        delete[] temp; temp = nullptr;
        return result;
    }
    else if(!this->isNegativeNumber() && other.isNegativeNumber())
    {
        // (+) - (-) == (+) + (+)
        char* temp = new(std::nothrow) char[other.size];
        if(!temp)
        {
            std::cout << "Memory not allocated successfully!\n";
            return BigNumber();
        }

        int j = 1;
        for(int i = 0; i < other.size - 1; i++)
        {
            temp[i] = other.data[j];
            j++;
        }
        temp[other.size - 1] = '\0';

        BigNumber result = *this + temp;
        delete[] temp; temp = nullptr;
        return result;
    }
    else // this->isNegativeNumber() && !other.isNegativeNumber()
    {
        // (-) - (+) == (-) + (-)
        char* temp = new(std::nothrow) char[other.size + 1];
        if(!temp)
        {
            std::cout << "Memory not allocated successfully!\n";
            return BigNumber();
        }

        strcpy(temp, other.data);
        addASymbolAtTheBeginning(temp, '-');

        BigNumber result = *this + temp;
        delete[] temp; temp = nullptr;
        return result;
    }
}

BigNumber& BigNumber::operator *= (const BigNumber& other)
{
    *this = *this * other;
    return *this;
}

BigNumber BigNumber::operator * (const BigNumber& other) const
{
    if(!this->isNegativeNumber() && !other.isNegativeNumber())
    {
        char* temp = (strlen(this->data) >= strlen(other.data)) ?
                      mult(this->data, other.data) :
                      mult(other.data, this->data);

        if(!temp) return BigNumber();

        BigNumber result(temp);
        delete[] temp; temp = nullptr;
        return result;

    }
    else if(this->isNegativeNumber() && other.isNegativeNumber())
    {
        char* num1 = removeMinus(this->data);
        char* num2 = removeMinus(other.data);

        char* temp = (strlen(num1) >= strlen(num2)) ?
                      mult(num1, num2) :
                      mult(num2, num1);

        delete[] num1; num1 = nullptr;
        delete[] num2; num2 = nullptr;

        if(!temp) return BigNumber();

        BigNumber result(temp);
        delete[] temp; temp = nullptr;
        return result;
    }
    else if(!this->isNegativeNumber() && other.isNegativeNumber())
    {
        char* num2 = removeMinus(other.data);

        char* temp = (strlen(this->data) >= strlen(num2)) ?
                      mult(this->data, num2) :
                      mult(num2, this->data);

        delete[] num2; num2 = nullptr;

        if(!temp) return BigNumber();

        addASymbolAtTheBeginning(temp, '-');

        BigNumber result(temp);
        delete[] temp; temp = nullptr;
        return result;
    }
    else // this->isNegativeNumber() && !other.isNegativeNumber()
    {
        char* num1 = removeMinus(this->data);

        char* temp = (strlen(num1) >= strlen(other.data)) ?
                      mult(num1, other.data) :
                      mult(other.data, num1);
 
        delete[] num1; num1 = nullptr;

        if(!temp) return BigNumber();

        addASymbolAtTheBeginning(temp, '-');

        BigNumber result(temp);
        delete[] temp; temp = nullptr;
        return result;
    }
}

void BigNumber::read()
{
    char temp[1024];

    std::cout << "Enter number:\n";
    std::cin.getline(temp, 1024);

    *this = BigNumber(temp);
}

void BigNumber::print() const
{
    std::cout << this->data;
}
