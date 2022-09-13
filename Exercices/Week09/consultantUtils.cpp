#include "consultantUtils.hpp"

#include <cstring>

bool ConsultantUtils::isGoodForGaming(const Computer& computer)
{
    return (strcmp(computer.getProcessor(), "i5") == 0 || strcmp(computer.getProcessor(), "i7") == 0) &&
           (computer.getVideo() == 3060 || computer.getVideo() == 3070 || computer.getVideo() == 3080 || computer.getVideo() == 3090) &&
           computer.getHardDrive() >= 512;
}

bool ConsultantUtils::isGoodForTravel(const Computer& computer)
{
    return computer.getWeight() <= 2.5 && computer.getBatteryLife() > 6; 
}
