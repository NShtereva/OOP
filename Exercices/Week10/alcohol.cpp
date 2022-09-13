#include "alcohol.hpp"

Alcohol::Alcohol(const char* name, const size_t quantity, const char* description, 
                        const double price, ServedIn servedIn, const double percentageOfAlcohol)
    : Drink(name, quantity, description, price, servedIn), percentageOfAlcohol(percentageOfAlcohol)
{ }

double Alcohol::getPercentageOfAlcohol() const
{
    return this->percentageOfAlcohol;
}

const char* Alcohol::getType() const
{
    return "alcohol";
}

void Alcohol::getInfo() const
{
    Drink::getInfo();
    std::cout << "percentage of alcohol: " << this->percentageOfAlcohol << std::endl;
}
