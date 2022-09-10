#ifndef __PLAYLIST_HPP
#define __PLAYLIST_HPP

#include "song.hpp"

class Playlist
{
    private:
        char* name;
        Song* songs;
        size_t numberOfSongs;
        size_t capacity;

        void allocate(const size_t size);

        void copy(const Playlist& other);
        void deallocate();

        size_t getCapacity() const;
        
        bool setNumberOfSongs(int numberOfSongs);
        bool setCapacity(int capacity);

        void resize();

    public:
        Playlist(const char* name);
        Playlist(const Playlist& other);
        ~Playlist();

        Playlist& operator = (const Playlist& other);

        const char* getName() const;
        size_t getNumberOfSongs() const;
        
        void setName(const char* name);

        int getSongIndex(const char* songName);
        void addSong(const Song& songToAdd);
        bool removeSong(const char* songName);
        void printPlaylistInfo() const;
};

#endif
