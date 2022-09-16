#ifndef __BOOK__HPP
#define __BOOK__HPP

#include <iostream>

class Book
{
    private:
        static const size_t MAX_LEN = 100;

        char title[Book::MAX_LEN];
        char author[Book::MAX_LEN];
        unsigned int circulation;

    public:
        Book();
        Book(const char* title, const char* author, const unsigned int circulation);

        const char* getTitle() const;
        const char* getAuthor() const;
        unsigned int getCirculation() const;

        void setTitle(const char* title);
        void setAuthor(const char* author);
        void setCirculation(const unsigned int circulation);

        friend std::ostream& operator << (std::ostream& out, const Book& book);
};

#endif
