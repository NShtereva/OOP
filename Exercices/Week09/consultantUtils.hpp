#ifndef __CONSULTANTUTILS_HPP
#define __CONSULTANTUTILS_HPP

#include "computer.hpp"

class ConsultantUtils 
{
    public:
        static bool isGoodForGaming(const Computer& computer);
        static bool isGoodForTravel(const Computer& computer);
};

#endif
