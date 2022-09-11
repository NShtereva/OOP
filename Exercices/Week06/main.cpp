#include <iostream>

#include "time.hpp"
#include "washingMashine.hpp"
#include "washingMashines.hpp"

void testTime()
{
    Time t1(20,45), t2(13,15), t3(22,30), t4, t5;
    std::cout << (t1 + t2);
    t3 = t1 + t2;
    std::cout << t3;
    t4 = t1 + 5;
    std::cout << t4;
    t5 = 6 + t1;
    std::cout << t5;
    std::cout <<  (t1 > t2) << std::endl;
    std::cout <<  (t3 > t2) << std::endl;
}

void testWM()
{
    WashingMashine wm1("AEG", "7000", 7, 3.5, 5);
    WashingMashine wm2("Miele", "WWD120", 8, 3.0, 6);
    WashingMashine wm3(wm1);
    WashingMashine wm4;
    wm4 = wm2;

    std::cout << wm1 << wm2 << wm3 << wm4;

    WashingMashine wm5("Indesit", "961480X", 6, 4.0, 10);

    std::cout << (wm1 > wm2) << std::endl;
    std::cout << (wm1 > wm5) << std::endl;
}

void testWashingMashines()
{
    WashingMashines wm;
    std::cin >> wm;
    std::cout << "\n" << wm;

    std::cout << std::endl;
    wm.WMWithTheBestCharacteristics();
}

int main()
{
    // testTime();
    // testWM();
    testWashingMashines();
    return 0;
}
