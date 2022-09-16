#include "book.hpp"

#include <cassert>
#include <cstring>

Book::Book()
{
    this->setTitle("-");
    this->setAuthor("-");
    this->setCirculation(0);
}

Book::Book(const char* title, const char* author, const unsigned int circulation)
{
    this->setTitle(title);
    this->setAuthor(author);
    this->setCirculation(circulation);
}

const char* Book::getTitle() const
{
    return this->title;
}

const char* Book::getAuthor() const
{
    return this->author;
}

unsigned int Book::getCirculation() const
{
    return this->circulation;
}

void Book::setTitle(const char* title)
{
    assert(title && strlen(title) < Book::MAX_LEN);
    strcpy(this->title, title);
}

void Book::setAuthor(const char* author)
{
    assert(author && strlen(author) < Book::MAX_LEN);
    strcpy(this->author, author);
}

void Book::setCirculation(const unsigned int circulation)
{
    this->circulation = circulation;
}

std::ostream& operator << (std::ostream& out, const Book& book)
{
    out << book.title       << ", "
        << book.author      << ", "
        << book.circulation << std::endl;

    return out;
}
