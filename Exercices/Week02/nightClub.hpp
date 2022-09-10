#ifndef __NIGHTCLUB_HPP
#define __NIGHTCLUB_HPP

#include "baloon.hpp"
#include "shisha.hpp"
#include "alcohol.hpp"

const unsigned int CAPACITY = 1000;

struct NightClub
{
    private:
        Baloon* balloons;
        Shisha* hoohahs;
        Alcohol* alcohols;

        unsigned int numberOfBalloons;
        unsigned int numberOfHookahs;
        unsigned int numberOfAlcohols;

        unsigned int getNumberOfBalloons() const;
        unsigned int getNumberOfHookahs() const;
        unsigned int getNumberOfAlcohols() const;

        void setNumberOfBalloons(unsigned int newSize);
        void setNumberOfHookahs(unsigned int newSize);
        void setNumberOfAlcohols(unsigned int newSize);

        int checkBalloonHelper(const char* color) const;
        int checkHoohahHelper(const char* brand, const char* taste) const;
        int checkAlcoholHelper(const char* name) const;

    public:
        NightClub();
        NightClub(const NightClub& other) = delete;
        ~NightClub();

        NightClub& operator = (const NightClub& other) = delete;

        void addBalloon();
        void addHoohah();
        void addAlcohol();

        void removeBalloon(const char* color);
        void removeHoohah(const char* brand, const char* taste);
        void removeAlcohol(const char* name);

        void checkBalloon(const char* color) const;
        void checkHoohah(const char* brand, const char* taste) const;
        void checkAlcohol(const char* name) const;

        void print() const;
};

#endif
