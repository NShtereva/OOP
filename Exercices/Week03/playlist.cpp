#include "playlist.hpp"

#include <cstring>

const size_t INITIAL_CAPACITY = 2;
const size_t INCREASE_STEP = 2;

Playlist::Playlist(const char* name) 
    : name(nullptr), songs(nullptr)
{
    this->setName(name);
    this->setNumberOfSongs(0);
    this->setCapacity(INITIAL_CAPACITY);

    this->allocate(INITIAL_CAPACITY);
}

Playlist::Playlist(const Playlist& other)
    : name(nullptr), songs(nullptr)
{
    this->copy(other);
}

Playlist::~Playlist()
{
    this->deallocate();
}

Playlist& Playlist::operator = (const Playlist& other)
{
    if(this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}

void Playlist::allocate(const size_t size)
{
    this->songs = new(std::nothrow) Song[size];
    if(this->songs == nullptr)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }
}

void Playlist::copy(const Playlist& other)
{
    this->setName(other.name);

    this->allocate(other.capacity);

    int size = other.numberOfSongs;

    for (int i = 0; i < size; ++i)
    {
        this->songs[i] = other.songs[i];
    }

    this->setNumberOfSongs(other.numberOfSongs);
    this->setCapacity(other.capacity);
}

void Playlist::deallocate()
{
    delete[] this->name;
    this->name = nullptr;

    delete[] this->songs;
    this->songs = nullptr;
}

const char* Playlist::getName() const
{
    return this->name;
}

size_t Playlist::getNumberOfSongs() const
{
    return this->numberOfSongs;
}

size_t Playlist::getCapacity() const
{
    return this->capacity;
}

void Playlist::setName(const char* name)
{
    if(!name) name = "";

    delete[] this->name;

    this->name = new (std::nothrow) char[strlen(name) + 1];
    if(this->name == nullptr)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    strcpy(this->name, name);
}

bool Playlist::setNumberOfSongs(int numberOfSongs)
{
    if(numberOfSongs >= 0 && numberOfSongs <= this->capacity)
    {
        this->numberOfSongs = numberOfSongs;
        return true;
    }

    return false;
}

bool Playlist::setCapacity(int capacity)
{
    if(capacity >= INITIAL_CAPACITY)
    {
        this->capacity = capacity;
        return true;
    }

    return false;
}

int Playlist::getSongIndex(const char* songName)
{
    int size = this->numberOfSongs;

    for(int i = 0; i < size; i++)
    {
        if(strcmp(this->songs[i].getName(), songName) == 0)
            return i;
    }

    return -1;
}

void Playlist::resize()
{
    Song* newArray = new(std::nothrow) Song[this->capacity * INCREASE_STEP];
    if(newArray == nullptr)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    int size = this->numberOfSongs;

    for (int i = 0; i < size; ++i)
    {
        newArray[i] = this->songs[i];
    }

    delete[] this->songs;

    this->songs = newArray;
    newArray = nullptr;

    this->setCapacity(this->capacity * INCREASE_STEP);
}

void Playlist::addSong(const Song& songToAdd)
{
    int index = this->getSongIndex(songToAdd.getName());
    if(index != -1)
    {
        std::cout << "There is already a song with that name in the playlist!\n";
        return;
    }

    int size = this->numberOfSongs;

    if(size + 1 <= this->capacity)
    {
        this->songs[size] = songToAdd;
        this->setNumberOfSongs(size + 1);
    }
    else
    {
        this->resize();

        this->songs[size] = songToAdd;
        this->setNumberOfSongs(size + 1);
    }
}

bool Playlist::removeSong(const char* songName)
{
    int songIndex = this->getSongIndex(songName);
    if(songIndex == -1) return false;

    Song tempSong(this->songs[songIndex]);
    this->songs[songIndex] = this->songs[this->numberOfSongs - 1];
    this->songs[this->numberOfSongs - 1] = tempSong;

    this->setNumberOfSongs(this->numberOfSongs - 1);

    return true;
}

void Playlist::printPlaylistInfo() const
{
    std::cout << "name: "            << this->name
              << ", number of songs: " << this->numberOfSongs << std::endl;
    
    int size = this->numberOfSongs;
    for(int i = 0; i < size; i++)
    {
        this->songs[i].print();
    }
}
