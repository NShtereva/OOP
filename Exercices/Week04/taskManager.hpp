#ifndef __TASKMANAGER_HPP
#define __TASKMANAGER_HPP

#include "task.hpp"

class TaskManager
{
    private:
        Task* taskManager;
        size_t capacity;
        size_t size;

        void allocate(const size_t size);
        void deallocate();
        void copy(const TaskManager& other);

        void setCapacity(int capacity);
        void setSize(int size);

        void resize();

    public:
        TaskManager();
        TaskManager(const TaskManager& other);
        TaskManager& operator = (const TaskManager& other);
        ~TaskManager();

        size_t getTaskCount() const;
        void addTask(const Task& task);
        void removeTask(const char* title);
        const Task& getNextTask() const;

        void print() const;
};

#endif
