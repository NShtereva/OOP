#include "taskManager.hpp"

#include <cassert>
#include <cstring>

const size_t INITIAL_CAPACITY = 2;
const size_t INCREASE_STEP = 2;

TaskManager::TaskManager()
{
    this->allocate(INITIAL_CAPACITY);
    this->setCapacity(INITIAL_CAPACITY);
    this->setSize(0);
}

TaskManager::TaskManager(const TaskManager& other)
{
    this->copy(other);
}

TaskManager& TaskManager::operator = (const TaskManager& other)
{
    if(this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}

TaskManager::~TaskManager()
{
    this->deallocate();
}

void TaskManager::allocate(const size_t size)
{
    this->taskManager = new(std::nothrow) Task[size];
    if(!this->taskManager)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }
}

void TaskManager::deallocate()
{
    delete[] this->taskManager;
    this->taskManager = nullptr;
}

void TaskManager::copy(const TaskManager& other)
{
    this->allocate(other.capacity);

    int n = other.size;

    for(int i = 0; i < n; i++)
    {
        this->taskManager[i] = other.taskManager[i];
    }

    this->setCapacity(other.capacity);
    this->setSize(other.size);
}

void TaskManager::resize()
{
    Task* newTaskManager = new(std::nothrow) Task[this->capacity * INCREASE_STEP];
    if(!newTaskManager)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    for(int i = 0; i < this->size; i++)
    {
        newTaskManager[i] = this->taskManager[i]; 
    }

    this->capacity *= INCREASE_STEP;

    this->deallocate();
    
    this->taskManager = newTaskManager;
    newTaskManager = nullptr;
}

size_t TaskManager::getTaskCount() const
{
    return this->size;
}

void TaskManager::setCapacity(int capacity)
{
    assert(capacity >= INITIAL_CAPACITY);
    this->capacity = capacity;
}

void TaskManager::setSize(int size)
{
    assert(size >= 0);
    this->size = size;
}

void TaskManager::addTask(const Task& task)
{
    if(this->size + 1 <= this->capacity)
    {
        this->taskManager[this->size] = task;
        this->setSize(this->size + 1);
    }
    else
    {
        this->resize();
        this->taskManager[this->size] = task;
        this->setSize(this->size + 1);
    }
}

void TaskManager::removeTask(const char* title)
{
    for(int i = 0; i < this->size; i++)
    {
        if(strcmp(this->taskManager[i].getTitle(), title) == 0)
        {
            Task temp(this->taskManager[i]);
            this->taskManager[i] = this->taskManager[this->size - 1];
            this->taskManager[this->size - 1] = temp;

            this->setSize(this->size - 1);
        }
    }
}

const Task& TaskManager::getNextTask() const
{
    int index = 0;

    for(int i = 1; i < this->size; i++)
    {  
        if(this->taskManager[i].getDeadline() < this->taskManager[index].getDeadline())
        {
            index = i;
        }
    }
 
    return this->taskManager[index];
}

void TaskManager::print() const
{
    int n = this->getTaskCount();

    for(int i = 0; i < n; i++)
    {
        this->taskManager[i].print();
    }
}
