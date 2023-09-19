#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include "Stack.h"
#include "StackOverflow.h"
#include "StackUnderflow.h"
#include "WrongStackSize.h"

template <class T>
class StackArray : public Stack<T>
{
private:
    T* arr;
    int size = 0;
    int top = -1;

public:
    StackArray(int s) : size(s), top(-1)
    {
        if (s <= 0)
        {
            throw WrongStackSize();
        }
        arr = new T[size];
    }

    StackArray(const StackArray<T>& src) = delete;
    StackArray(StackArray<T>&& src) = delete;
    StackArray& operator=(const StackArray<T>& src) = delete;
    StackArray& operator=(StackArray<T>&& src) = delete;

    ~StackArray()
    {
        delete[] arr;
    }

    void push(const T& element)
    {
        if (top == size - 1)
        {
            throw StackOverflow();
        }
        top++;
        arr[top] = element;
    }

    T pop()
    {
        if (top == -1)
        {
            throw StackUnderflow();
        }
        T element = arr[top];
        top--;
        return element;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    T topp()
    {
        if (isEmpty())
        {
            throw StackUnderflow();
        }
        return arr[top];

    }

};


#endif // !STACKARRAY_H

