#ifndef __TASK_HPP
#define __TASK_HPP

#include "date.hpp"
#include "category.hpp"

class Task
{
    private:
        char* title;
        char* description;
        Date* deadline;
        Category category;

    public:
        Task();
        Task(const char* title, const char* description, const Date& deadline, const Category& category);
        Task(const Task& other);
        Task& operator = (const Task& other);
        ~Task();

        const char* getTitle() const;
        const char* getDescription() const;
        Date getDeadline() const;
        Category getCategory() const;

        void setTitle(const char* title);
        void setDescription(const char* description);
        void setDeadline(const Date& deadline);
        void setCategory(const Category& category);

        void print() const;
};

#endif
