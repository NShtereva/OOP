#include "task.hpp"

#include <cstring>

Task::Task() : title(nullptr), description(nullptr), deadline(nullptr)
{
    this->setTitle("");
    this->setDescription("");
    this->setDeadline(Date(1,1,2000));
    this->setCategory(Category::OTHER);
}

Task::Task(const char* title, const char* description, const Date& deadline, const Category& category)
    : title(nullptr), description(nullptr), deadline(nullptr)
{
    this->setTitle(title);
    this->setDescription(description);
    this->setDeadline(deadline);
    this->setCategory(category);
}

Task::Task(const Task& other)
     : title(nullptr), description(nullptr), deadline(nullptr)
{
    this->setTitle(other.title);
    this->setDescription(other.description);
    this->setDeadline(*other.deadline);
    this->setCategory(other.category);
}

Task& Task::operator = (const Task& other)
{
     if(this != &other)
    {
        this->setTitle(other.title);
        this->setDescription(other.description);
        this->setDeadline(*other.deadline);
        this->setCategory(other.category);
    }

    return *this;
}

Task::~Task()
{
    delete[] this->title;
    this->title = nullptr;

    delete[] this->description;
    this->description = nullptr;
    
    delete[] this->deadline;
    this->deadline = nullptr;
}

const char* Task::getTitle() const
{
    return this->title;
}

const char* Task::getDescription() const
{
    return this->description;
}

Date Task::getDeadline() const
{
    return (*this->deadline);
}

Category Task::getCategory() const
{
    return this->category;
}

void Task::setTitle(const char* title)
{
    if(!title) title = "";

    delete[] this->title;

    this->title = new(std::nothrow) char[strlen(title) + 1];
    if(!this->title)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    strcpy(this->title, title);
}

void Task::setDescription(const char* description)
{
    if(!description) description = "";

    delete[] this->description;

    this->description = new(std::nothrow) char[strlen(description) + 1];
    if(!this->description)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    strcpy(this->description, description);
}

void Task::setDeadline(const Date& deadline)
{
    delete[] this->deadline;

    this->deadline = new(std::nothrow) Date(deadline);
    if(!this->deadline)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }
}

void Task::setCategory(const Category& category)
{
    this->category = category;
}

void Task::print() const
{
    std::cout << "title: " << this->title << "\ndescription: " << this->description
              << "\ndeadline: " << this->deadline->day() << "." << this->deadline->month() << "." << this->deadline->year();
    std::cout << std::endl;
}
