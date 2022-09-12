#include "university.hpp"

#include <cassert>

const size_t INITIAL_CAPACITY = 2;
const size_t INCREASE_STEP = 2;

University::University()
{
    this->allocate(INITIAL_CAPACITY);
    this->setCapacity(INITIAL_CAPACITY);
    this->setSize(0);
}

University::University(const University& other)
{ 
    this->copy(other);
}

University::~University()
{
    this->deallocate();
}

University& University::operator = (const University& other)
{
    if(this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}

void University::allocate(const size_t size)
{
    this->students = new(std::nothrow) Student*[size];
    if(!this->students)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }
}

void University::copy(const University& other)
{
    this->allocate(other.capacity);
    this->setCapacity(other.capacity);
    this->setSize(other.size);

    for(int i = 0; i < this->size; i++)
    {
       this->students[i] = new Student(*other.students[i]);
    }
}

void University::deallocate()
{
    for(int i = 0; i < this->size; i++)
    {
        delete this->students[i];
    } delete[] this->students;
}

void University::setSize(const int size)
{
    assert(size >= 0 && size <= this->capacity);
    this->size = size;
}

void University::setCapacity(const int capacity)
{
    assert(capacity >= INITIAL_CAPACITY);
    this->capacity = capacity;
}

void University::resize()
{
    Student** newArr = new(std::nothrow) Student*[this->capacity * INCREASE_STEP];
    if(!newArr)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    for(int i = 0; i < this->size; i++)
    {
        newArr[i] = this->students[i];
    }

    delete[] this->students;

    this->students = newArr;
    newArr = nullptr;

    this->setCapacity(this->capacity * INCREASE_STEP);
}

size_t University::getSize() const
{
    return this->size;
}

void University::sort(bool(*cmp)(const Student&, const Student&))
{
    for(int i = 0; i < this->size; i++)
    {
        for(int j = i + 1; j < this->size; j++)
        {
            if(cmp(*this->students[i], *this->students[j]))
            {
                Student* temp = this->students[i];
                this->students[i] = this->students[j];
                this->students[j] = temp;
            }
        }
    }
}

void University::filter(bool(*pred)(const Student&))
{
    for(int i = 0; i < this->size; i++)
    {
        if(pred(*this->students[i]))
        {
            std::cout << *this->students[i];
        }
    }
}

University& University::operator += (const Student& st)
{
    bool isFound = false;

    for(int i = 0; i < this->size && !isFound; i++)
    {
        if(this->students[i]->getFN() == st.getFN())
        {
            isFound = true;
        }
    }

    if(isFound)
    {
        std::cout << "\nAlready has a student with faculty number: " << st.getFN() << "!\n";
        return *this;

    }

    if(this->size + 1 > this->capacity)
    {
        resize();
    }

    this->students[this->size] = new Student(st);
    this->setSize(this->size + 1);

    return *this;
}

University& University::operator -= (int fn)
{
    assert(this->size > 0);

    bool removed = false;

    for(int i = 0; i < this->size && !removed; i++)
    {
        if(this->students[i]->getFN() == fn)
        {
            Student* save = this->students[i];

            for(int j = i; j < this->size - 1; j++)
            {
                this->students[j] = this->students[j + 1];
            }

            delete save;

            removed = true;
            this->setSize(this->size - 1);
        }
    }

    return *this;
}

const Student& University::operator [] (size_t i) const
{
    assert(i < this->size);
    return *this->students[i];
}

Student& University::operator [] (size_t i)
{
    assert(i < this->size);
    return *this->students[i];
}

std::ostream& operator << (std::ostream& out, const University& uni)
{
    out << uni.size << "\n";

    for(int i = 0; i < uni.size; i++)
    {
        out << *uni.students[i];
    }

    return out;
}

std::istream& operator >> (std::istream& in, University& uni)
{
    unsigned int size;
    in >> size;

    for(int i = 0; i < size; i++)
    {
        Student temp;
        in >> temp;
        uni += temp;
    }

    return in;
}
