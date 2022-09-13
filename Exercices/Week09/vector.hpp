#ifndef __VECTOR_HPP
#define __VECTOR_HPP

#include <iostream>
#include <fstream>
#include <cassert>

const size_t INITIAL_CAPACITY = 2;
const size_t INCREASE_STEP = 2;

template <typename T>
class Vector
{
    private:
        T* elements;
        size_t size;
        size_t capacity;

        void allocate(const int size);
        void copy(const Vector& other);
        void deallocate();

        void setSize(const int size);
        void setCapacity(const int capacity);

        void resize();

    public:
        Vector();
        Vector(const Vector& other);
        ~Vector();

        Vector& operator = (const Vector& other);

        size_t getSize() const;

        void add(const T& elem);
        void remove(int position);

        bool empty() const;

        T& operator [] (int index);
        const T operator [] (int index) const;

        template <typename U>
        friend std::ostream& operator << (std::ostream& out, const Vector<U>& vector);
        
        template <typename U>
        friend std::istream& operator >> (std::istream& in, Vector<U>& vector);
};

template <typename T>
Vector<T>::Vector()
{
    this->allocate(INITIAL_CAPACITY);
    this->setCapacity(INITIAL_CAPACITY);
    this->setSize(0);
}

template <typename T>
Vector<T>::Vector(const Vector& other)
{
    this->copy(other);
}

template <typename T>
Vector<T>::~Vector()
{
    this->deallocate();
}

template <typename T>
Vector<T>& Vector<T>::operator = (const Vector& other)
{
    if(this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}

template <typename T>
void Vector<T>::allocate(const int size)
{
    this->elements = new(std::nothrow) T[size];
    if(!this->elements)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }
}

template <typename T>
void Vector<T>::copy(const Vector& other)
{
    this->allocate(other.capacity);

    for(int i = 0; i < other.size; i++)
    {
        this->elements[i] = other.elements[i];
    }

    this->setCapacity(other.capacity);
    this->setSize(other.size);
}

template <typename T>
void Vector<T>::deallocate()
{
    delete[] this->elements;
    this->elements = nullptr;
}

template <typename T>
void Vector<T>::setSize(const int size)
{
    assert(size >= 0 && size <= this->capacity);
    this->size = size;
}

template <typename T>
void Vector<T>::setCapacity(const int capacity)
{
    assert(capacity >= INITIAL_CAPACITY);
    this->capacity = capacity;
}

template <typename T>
void Vector<T>::resize()
{
    T* newArr = new(std::nothrow) T[this->capacity * INCREASE_STEP];
    if(!newArr)
    {
        std::cout << "Memory not allocated successfully!\n";
        return;
    }

    for(int i = 0; i < this->size; i++)
    {
        newArr[i] = this->elements[i];
    }

    this->deallocate();
    this->elements = newArr;
    newArr = nullptr;

    this->setCapacity(this->capacity * INCREASE_STEP);
}

template <typename T>
size_t Vector<T>::getSize() const
{
    return this->size;
}

template <typename T>
void Vector<T>::add(const T& elem)
{
    if(this->size + 1 > this->capacity)
    {
        resize();
    }

    this->elements[this->size] = elem;
    this->setSize(this->size + 1);
}

template <typename T>
void Vector<T>::remove(int position)
{
    assert(this->size > 0);
    assert(position >= 0 && position < this->size);

    T temp = this->elements[position];
    this->elements[position] = this->elements[this->size - 1];
    this->elements[this->size - 1] = temp;

    this->setSize(this->size - 1);
}

template <typename T>
bool Vector<T>::empty() const
{
    return this->size == 0;
}

template <typename T>
T& Vector<T>::operator [] (int index)
{
    assert(index >= 0 && index < this->size);
    return this->elements[index];
}

template <typename T>
const T Vector<T>::operator [] (int index) const
{
    assert(index >= 0 && index < this->size);
    return this->elements[index];
}

template <typename U>
std::ostream& operator << (std::ostream& out, const Vector<U>& vector)
{
    out << vector.size << std::endl;

    for(int i = 0; i < vector.size; i++)
    {
        out << vector.elements[i] << std::endl;
    }

    return out;
}

template <typename U>
std::istream& operator >> (std::istream& in, Vector<U>& vector)
{
    unsigned int size;
    in >> size;

    for(int i = 0; i < size; i++)
    {
        U temp;
        in >> temp;
        vector.add(temp);
    }

    return in;
}

#endif
