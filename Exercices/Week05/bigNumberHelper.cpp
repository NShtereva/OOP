#include "bigNumberHelper.hpp"

// number >= 0
long long int reverse(const long long int& number)
{
    long long int reverseNum = 0, copy = number;

    while (copy != 0)
    {
        int temp = copy % 10;
        copy = copy / 10;
        reverseNum = reverseNum * 10 + temp;
    }

    return reverseNum;
}

// number > 0
size_t numberOfDigits(const long long int& number)
{
    long long int copy = number;
    size_t numberOfDigits = 0;

    while (copy != 0)
    {
        numberOfDigits++;
        copy = copy / 10;
    }

    return numberOfDigits;
}

// number < 0
char* removeMinus(const char* number)
{
    int len = strlen(number);

    char* result = new(std::nothrow) char[len]; // without '-'
    if(!result)
    {
        std::cout << "Memory not allocated successfully!\n";
        return nullptr;
    }

    int j = 1;
    for(int i = 0; i < len - 1; i++)
    {
        result[i] = number[j];
        j++;
    }

    result[len - 1] = '\0';
    
    return result;
}

// number1 >= 0 && number2 >= 0 && strlen(number1) == strlen(number2)
bool lessThan(const char* number1, const char* number2)
{
    int len = strlen(number1);
    for(int i = 0; i < len; i++)
    {
        if((number1[i] - '0') < (number2[i] - '0')) return true;
    }

    return false;
}

void addASymbolAtTheBeginning(char*& data, const char symbol)
{
    int len = strlen(data);

    char* newData = new(std::nothrow) char[len + 2];  // strlen(data) + symbol + '\0'
    if(!newData)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    newData[0] = symbol;

    for(int i = 1; i < len + 1; i++)
    {
        newData[i] = data[i - 1];
    }

    newData[len + 1] = '\0';

    delete[] data;
    data = newData;
    newData = nullptr;
}

// number1 >= 0 && number2 >= 0 && strlen(number1) > strlen(number2)
char* sumOfTwoPositiveNumbers(const char* number1, const char* number2)
{
    int len = strlen(number1);

    char* result = new(std::nothrow) char[len + 1];
    if(!result)
    {
        std::cout << "Memory not allocated successfully!\n";
        return nullptr;
    }

    strcpy(result, number1);

    int i, j = strlen(number2) - 1, plusOne = 0;

    for(i = len - 1; i >= 0 && j >= 0; i--)
    {
        int temp = (result[i] - '0') + (number2[j] - '0');
        result[i] = (temp + plusOne) % 10 + '0';
        plusOne = (temp + plusOne > 9) ? 1 : 0;
        j--;
    }
    
    while (i >= 0 && plusOne == 1)
    {
        int temp = (result[i] - '0') + plusOne;
        result[i] = temp % 10 + '0';
        plusOne = (temp > 9) ? 1 : 0;
        i--;
    }

    if(i == -1 && plusOne == 1)
    {
        addASymbolAtTheBeginning(result, '1');
    }

    return result;
}

// number1 >= 0 && number2 >= 0 && strlen(number1) >= strlen(number2)
char* subtractionHelper(const char* number1, const char* number2)
{
    int len1 = strlen(number1), len2 = strlen(number2);

    char* result = new(std::nothrow) char[len1 + 1];
    if(!result)
    {
        std::cout << "Memory not allocated successfully!\n";
        return nullptr;
    }

    int i = len1 - 1, j = len2 - 1, minusOne = 0;
    while(j >= 0)
    {
        int temp1 = (number1[i] - '0') + minusOne;
        int temp2 = number2[j] - '0';

        if(temp1 < temp2)
        {
            temp1 = temp1 + 10;
            minusOne = -1;
            result[i] = (temp1 - temp2) + '0';
        }
        else
        {
            result[i] = (temp1 - temp2) + '0';
            minusOne = 0;
        }

        i--; j--;
    }

    if(i >= 0 && minusOne == -1)
    {
        result[i] = ((number1[i] - '0') + minusOne) + '0';
        i--;
    }

    while(i >= 0)
    {
        result[i] = number1[i];
        i--;
    }

    result[len1] = '\0';

    if(result[0] - '0' == 0)
    {
        for(int i = 1; i < len1; i++)
        {
            result[i - 1] = result[i];
        }
        result[len1 - 1] = '\0';
    }

    return result;
}

// number1 >= 0 && number2 >= 0
char* subtractionOfTwoPositiveNumbers(const char* number1, const char* number2)
{
    char* result;

    if(strlen(number1) >= strlen(number2))
    {
        result = subtractionHelper(number1, number2);
    }
    else
    {
        result = subtractionHelper(number2, number1);
        addASymbolAtTheBeginning(result, '-');
    }

    return result;
}

char* multByDigit(const char* number, const char digit)
{
    int len = strlen(number);

    char* result = new(std::nothrow) char[len + 1];
    if(!result)
    {
        std::cout << "Memory not allocated successfully!\n";
        return nullptr;
    }

    int p = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        int temp = (number[i] - '0') * (digit - '0');

        result[i] = ((temp + p) % 10) + '0';

        p = (temp + p > 9) ? ((temp + p) / 10) % 10 : 0;
    }
    result[len] = '\0';

    if (p != 0)
    {
        addASymbolAtTheBeginning(result, (p + '0'));
    }

    return result;
}

char* addZerosAtTheEnd(char* number, const int numberOfZeros)
{
    if(numberOfZeros == 0) return number;

    int len = strlen(number) + numberOfZeros;

    char* result = new(std::nothrow) char[len + 1];
    if(!result)
    {
        std::cout << "Memory not allocated successfully!\n";
        return nullptr;
    }

    int k = 0;

    for (int i = 0; i < len - numberOfZeros; i++)
    {
        result[i] = number[k];
        k++;
    }

    for (int i = len - numberOfZeros; i < len; i++)
    {
        result[i] = '0';
    }
    result[len] = '\0';

    return result;
}

// number1 >= 0 && number2 >= 0  && strlen(number1) >= strlen(number2)
char* mult(const char* number1, const char* number2)
{
    if(strcmp(number1, "0") == 0 || strcmp(number2, "0") == 0) 
    {
        char* result = new(std::nothrow) char[2]; // '0' + '\0'
        if(!result)
        {
            std::cout << "Memory not allocated successfully!\n";
            return nullptr;
        }
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    int len1 = strlen(number1), len2 = strlen(number2), len = len1 + len2;

    char* result = new(std::nothrow) char[len + 1];
    if(!result)
    {
        std::cout << "Memory not allocated successfully!\n";
        return nullptr;
    }

    result[0] = '0';
    result[1] = '\0';

    int numberOfZeros = 0, tempResSize = 0;

    for (int i = len2 - 1; i >= 0; i--)
    {
        char* temp1 = multByDigit(number1, number2[i]);

        char* temp2 = addZerosAtTheEnd(temp1, numberOfZeros);

        result = (strlen(result) > strlen(temp2)) ? 
                 sumOfTwoPositiveNumbers(result, temp2) : 
                 sumOfTwoPositiveNumbers(temp2, result);

        if(!result) return nullptr;
        
        result[tempResSize + strlen(temp2)] = '\0';

        delete[] temp1; temp1 = nullptr;
        delete[] temp2; temp2 = nullptr;

        numberOfZeros++;
        tempResSize = strlen(result);
    }

    return result;
}
