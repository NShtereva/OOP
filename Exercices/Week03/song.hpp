#ifndef __SONG_HPP
#define __SONG_HPP

#include "duration.hpp"

class Song
{
    private:
        char* name;
        Duration duration;
        char* genre;

    public:
        Song();
        Song(const char* name, const Duration& duration, const char* genre);
        Song(const Song& other);
        ~Song();

        Song& operator = (const Song& other);

        const char* getName() const;
        Duration getDuration() const;
        const char* getGenre() const;

        void setName(const char* name);
        void setDuration(const Duration& duration);
        void setGenre(const char* genre);

        void print() const;
};

#endif
