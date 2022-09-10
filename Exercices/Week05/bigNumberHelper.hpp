#ifndef __BIGNUMBERHELPER_HPP
#define __BIGNUMBERHELPER_HPP

#include <iostream>
#include <cstring>

// number >= 0
long long int reverse(const long long int& number);

// number > 0
size_t numberOfDigits(const long long int& number);

// number < 0
char* removeMinus(const char* number);

// number1 >= 0 && number2 >= 0 && strlen(number1) == strlen(number2)
bool lessThan(const char* number1, const char* number2);

void addASymbolAtTheBeginning(char*& data, const char symbol);

// number1 >= 0 && number2 >= 0 && strlen(number1) > strlen(number2)
char* sumOfTwoPositiveNumbers(const char* number1, const char* number2);

// number1 >= 0 && number2 >= 0 && strlen(number1) >= strlen(number2)
char* subtractionHelper(const char* number1, const char* number2);

// number1 >= 0 && number2 >= 0
char* subtractionOfTwoPositiveNumbers(const char* number1, const char* number2);

char* multByDigit(const char* number, const char digit);

char* addZerosAtTheEnd(char* number, const int numberOfZeros);

// number1 >= 0 && number2 >= 0  && strlen(number1) >= strlen(number2)
char* mult(const char* number1, const char* number2);

#endif
