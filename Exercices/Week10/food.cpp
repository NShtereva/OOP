#include "food.hpp"

Food::Food(const char* name, const size_t quantity, const char* description, 
                                    const double price, bool isSmall, bool suitableForVegans)
    : MenuItem(name, quantity, description, price), isSmall(isSmall), suitableForVegans(suitableForVegans)
{ }

const char* Food::getType() const
{
    return "food";
}

void Food::getInfo() const
{
    std::cout << "type: " << this->getType() << std::endl;
    MenuItem::getInfo();
    std::cout << "portion: "               << ((this->isSmall) ? "small" : "large");
    std::cout << ", suitable for vegans: " << ((this->suitableForVegans) ? "yes" : "no");
    std::cout << std::endl;
}
