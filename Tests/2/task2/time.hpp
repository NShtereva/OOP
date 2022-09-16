#ifndef __TIME_HPP
#define __TIME_HPP

class Time
{
    private:
        unsigned int hour;
        unsigned int min;

    public:
        Time(unsigned int hour = 0, unsigned int min = 0);

        bool operator < (const Time& other) const;
        bool operator <= (const Time& other) const;
        
        unsigned int diff(const Time& other) const;
        const Time add20Min() const;
};

#endif
