#include "song.hpp"

#include <cstring>

Song::Song() : name(nullptr), genre(nullptr), duration(Duration())
{
    this->setName("-");
    this->setGenre("-");
}

Song::Song(const char* name, const Duration& duration, const char* genre) 
    : name(nullptr), genre(nullptr), duration(duration)
{
    this->setName(name);
    this->setGenre(genre);
}

Song::Song(const Song& other)
    : name(nullptr), genre(nullptr), duration(other.duration)
{
    this->setName(other.name);
    this->setGenre(other.genre);
}

Song::~Song()
{
    delete[] this->name;
    this->name = nullptr;

    delete[] this->genre;
    this->genre = nullptr;
}

Song& Song::operator = (const Song& other)
{
    if(this != &other)
    {
        this->setName(other.name);
        this->setGenre(other.genre);
        this->setDuration(other.duration);
    }

    return *this;
}

const char* Song::getName() const
{
    return this->name;
}

Duration Song::getDuration() const
{
    return this->duration;
}

const char* Song::getGenre() const
{
    return this->genre;
}

void Song::setName(const char* name)
{
    if(!name) name = "";

    delete[] this->name;

    this->name = new(std::nothrow) char[strlen(name) + 1];
    if(this->name == nullptr)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    strcpy(this->name, name);
}

void Song::setDuration(const Duration& duration)
{
    this->duration.setMin(duration.getMin());
    this->duration.setSec(duration.getSec());
}

void Song::setGenre(const char* genre)
{
    if(!genre) genre = "";

    delete[] this->genre;

    this->genre = new(std::nothrow) char[strlen(genre) + 1];
    if(this->genre == nullptr)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    strcpy(this->genre, genre);
}

void Song::print() const
{
    std::cout << "name: " << this->name << ", duration: ";
    this->duration.print();
    std::cout << ", genre: " << this->genre << std::endl;
}
