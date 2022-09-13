#ifndef __COMPUTER_HPP
#define __COMPUTER_HPP

#include <iostream>
#include <fstream>

class Computer
{
    private:
        static size_t counter;
        size_t serialNumber;
        char* brand;
        char* processor;
        size_t video;
        size_t hardDrive;
        double weight;
        double batteryLife;
        double price;
        size_t quantity; 

    public:
        Computer();
        Computer(const char* brand, const char* processor, const int video, const int hardDrive,
                    const double weight, const double batteryLife, const double price, const int quantity);
        Computer(const Computer& other);
        ~Computer();

        Computer& operator = (const Computer& other);

        size_t getSerialNumber() const;
        const char* getBrand() const;
        const char* getProcessor() const;
        size_t getVideo() const;
        size_t getHardDrive() const;
        double getWeight() const;
        double getBatteryLife() const;
        double getPrice() const;
        size_t getQuantity() const;

        void setBrand(const char* brand);
        void setProcessor(const char* processor);
        void setVideo(const int video);
        void setHardDrive(const int hardDrive);
        void setWeight(const double weight);
        void setBatteryLife(const double batteryLife);
        void setPrice(const double price);
        void setQuantity(const int quantity);

        friend std::istream& operator >> (std::istream& in, Computer& computer);
        friend std::ostream& operator << (std::ostream& out, const Computer& computer);
};

#endif
