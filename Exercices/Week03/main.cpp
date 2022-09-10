#include "duration.hpp"
#include "song.hpp"
#include "playlist.hpp"

void testDuration()
{
    Duration d1;
    d1.print();
    std::cout << std::endl;

    d1.setMin(4);
    d1.setSec(25);
    d1.print();
    std::cout << std::endl;

    Duration d2(3, 59);
    std::cout << d2.getMin() << ":" << d2.getSec();
    std::cout << std::endl;
}

void testSong()
{
    Song s1("song1", Duration(4, 25), "genre1");
    s1.print();

    Song s2;
    s2.print();

    s2.setName("name2");
    s2.setDuration(Duration(3, 59));
    s2.setGenre("genre2");

    std::cout << "name: " << s2.getName() << ", duration: ";
    s2.getDuration().print();
    std::cout << ", genre: " << s2.getGenre() << "\n";
}

void testPlaylist()
{
    Playlist p1("Playlist1");
    p1.printPlaylistInfo();

    p1.addSong(Song("name1", Duration(4, 25), "genre1"));
    p1.addSong(Song("name2", Duration(5, 0), "genre1"));
    p1.addSong(Song("name3", Duration(3, 59), "genre1"));
    p1.addSong(Song("name4", Duration(4, 45), "genre1"));

    std::cout << std::endl;
    p1.printPlaylistInfo();

    std::cout << "\n" << p1.getSongIndex("name3") << "\n";

    Playlist p2(p1), p3("Playlist3");
    p2.setName("Playlist2");

    p1.removeSong("name1");
    p1.removeSong("name2");

    p3 = p1;

    p1.removeSong("name3");
    p1.removeSong("name4");

    std::cout << std::endl;
    p1.printPlaylistInfo();

    std::cout << std::endl;
    p2.printPlaylistInfo();

    std::cout << std::endl;
    p3.printPlaylistInfo();
}

int main()
{
    // testDuration();
    // testSong();
    testPlaylist();
    return 0;
}
