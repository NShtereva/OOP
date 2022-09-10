#include "bigNumber.hpp"

void operatorsTesting()
{
    std::cout << std::boolalpha << (BigNumber("7643276342876783246893247") > BigNumber("4767846784647856547476")) << std::endl;
    std::cout << std::boolalpha << (BigNumber("4767846784647856547476") < BigNumber("7643276342876783246893247")) << std::endl;
    std::cout << std::boolalpha << (BigNumber("7643276342876783246893247") != BigNumber("4767846784647856547476")) << std::endl;
    std::cout << std::boolalpha << (BigNumber("7643276342876783246893247") == BigNumber("7643276342876783246893247")) << std::endl;
    
    std::cout << std::boolalpha << ((BigNumber("12345678901234567890") + BigNumber("4354678097643135")) == BigNumber("12350033579332211025")) << std::endl;
    std::cout << std::boolalpha << ((BigNumber("-12345678901234567890") + BigNumber("4354678097643135")) == BigNumber("-12341324223136924755")) << std::endl;
    std::cout << std::boolalpha << ((BigNumber(-98654863325) + BigNumber(-645843546546)) == BigNumber(-744498409871)) << std::endl;
    std::cout << std::boolalpha << ((BigNumber(-645843546546) + BigNumber(-98654863325)) == BigNumber(-744498409871)) << std::endl;
    std::cout << std::boolalpha << ((BigNumber(15458431213464) + BigNumber(1354643235448)) == BigNumber(16813074448912)) << std::endl;
    std::cout << std::boolalpha << ((BigNumber(1354643235448) + BigNumber(15458431213464)) == BigNumber(16813074448912)) << std::endl;
    std::cout << std::boolalpha << ((BigNumber(15458431213464) + BigNumber(-645843546546)) == BigNumber(14812587666918)) << std::endl;
    std::cout << std::boolalpha << ((BigNumber(-645843546546) + BigNumber(15458431213464)) == BigNumber(14812587666918)) << std::endl;
    std::cout << std::boolalpha << ((BigNumber(1354643235448) + BigNumber(-98654863325)) == BigNumber(1255988372123)) << std::endl;
    std::cout << std::boolalpha << ((BigNumber(-98654863325) + BigNumber(1354643235448)) == BigNumber(1255988372123)) << std::endl;
    std::cout << std::boolalpha << ((BigNumber(9999) + BigNumber(999)) == BigNumber(10998)) << std::endl;

    std::cout << std::boolalpha << ((BigNumber("12345678901234567890") - BigNumber("4354678097643135")) == BigNumber("12341324223136924755")) << std::endl;
    std::cout << std::boolalpha << ((BigNumber(-98654863325) - BigNumber(-645843546546)) == BigNumber(547188683221)) << std::endl;
    std::cout << std::boolalpha << ((BigNumber(-645843546546) - BigNumber(-98654863325)) == BigNumber(-547188683221)) << std::endl;
    std::cout << std::boolalpha << ((BigNumber(15458431213464) - BigNumber(1354643235448)) == BigNumber(14103787978016)) << std::endl;
    std::cout << std::boolalpha << ((BigNumber(1354643235448) - BigNumber(15458431213464)) == BigNumber(-14103787978016)) << std::endl;
    std::cout << std::boolalpha << ((BigNumber(15458431213464) - BigNumber(-645843546546)) == BigNumber("16104274760010")) << std::endl;
    std::cout << std::boolalpha << ((BigNumber(-645843546546) - BigNumber(15458431213464)) == BigNumber("-16104274760010")) << std::endl;
    std::cout << std::boolalpha << ((BigNumber(1354643235448) - BigNumber(-98654863325)) == BigNumber(1453298098773)) << std::endl;
    std::cout << std::boolalpha << ((BigNumber(-98654863325) - BigNumber(1354643235448)) == BigNumber(-1453298098773)) << std::endl;
    std::cout << std::boolalpha << ((BigNumber(9999) - BigNumber(9999)) == BigNumber("0")) << std::endl;
    
    std::cout << std::boolalpha << ((BigNumber("12345678901234567890") * BigNumber("4354678097643135")) == BigNumber("53761457511741137249987999149935150")) << std::endl;
    std::cout << std::boolalpha << ((BigNumber("-12345678901234567890") * BigNumber("4354678097643135")) == BigNumber("-53761457511741137249987999149935150")) << std::endl;
}

void readWriteTest()
{
    BigNumber number1, number2, save;
    number1.read();
    number2.read();

    std::cout << std::endl;
    
    number1.print(); std::cout << " += "; number2.print(); 
    save = number1;
    number1 += number2;
    std::cout << " = "; number1.print(); std::cout << std::endl;

    number1 = save;

    number1.print(); std::cout << " -= "; number2.print(); 
    save = number1;
    number1 -= number2;
    std::cout << " = "; number1.print(); std::cout << std::endl;

    number1 = save;

    number1.print(); std::cout << " *= "; number2.print(); 
    save = number1;
    number1 *= number2;
    std::cout << " = "; number1.print(); std::cout << std::endl;
}

int main()
{
    operatorsTesting();

    std::cout << std::endl;
    readWriteTest();
    
    return 0;
}
