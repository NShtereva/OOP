#include "baloon.hpp"
#include "shisha.hpp"
#include "alcohol.hpp"
#include "nightClub.hpp"

void testBaloon()
{
    Baloon b1;
    b1.read();
    b1.print();

    Baloon b2("white", 5);
    std::cout << "\ncolor: " 
              << b2.getColor() 
              << ", price: " 
              << b2.getPrice()
              << std::endl;

    b2.setColor("black");
    b2.setPrice(6);

    b2.print();
}

void testShisha()
{
    Shisha h1;
    h1.read();
    h1.print();

    Shisha h2("brand2", "taste2", 40);
    std::cout << "\nbrand: " 
              << h2.getBrand() 
              << ", taste: " 
              << h2.getTaste()
              << ", price: " 
              << h2.getPrice()
              << std::endl;

    h2.setBrand("brand3");
    h2.setTaste("taste3");
    h2.setPrice(30);

    h2.print();
}

void testAlcohol()
{
    Alcohol a1;
    a1.read();
    a1.print();

    Alcohol a2("name2", 100);
    std::cout << "\nname: " 
              << a2.getName() 
              << ", price: " 
              << a2.getPrice()
              << std::endl;

    a2.setName("name3");
    a2.setPrice(120);

    a2.print();
}

void testNightClub()
{
    NightClub club;

    club.addBalloon();
    club.addBalloon();
    club.addBalloon();

    std::cout << std::endl;

    std::cin.get();

    club.addHoohah();
    club.addHoohah();
    club.addHoohah();

    std::cout << std::endl;
    
    std::cin.get();

    club.addAlcohol();
    club.addAlcohol();
    club.addAlcohol();

    std::cout << std::endl;

    club.print();

    std::cout << std::endl;

    club.removeBalloon("color1");
    // club.removeBalloon("color2");
    // club.removeBalloon("color3");

    // club.removeHoohah("brand1", "taste1");
    club.removeHoohah("brand2", "taste2");
    // club.removeHoohah("brand3", "taste3");

    // club.removeAlcohol("name1");
    // club.removeAlcohol("name2");
    club.removeAlcohol("name3");

    club.print();

    std::cout << std::endl;
    std::cout << std::endl;

    club.checkBalloon("color1");
    club.checkBalloon("color2");
    club.checkBalloon("color3");

    club.checkHoohah("brand1", "taste1");
    club.checkHoohah("brand2", "taste2");
    club.checkHoohah("brand3", "taste3");

    club.checkAlcohol("name1");
    club.checkAlcohol("name2");
    club.checkAlcohol("name3");
}

int main()
{
    // testBaloon();
    // testShisha();
    // testAlcohol();
    testNightClub();
    return 0;
}
