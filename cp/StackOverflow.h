#ifndef STACK_OVERFLOW_H
#define STACK_OVERFLOW_H

#include <exception>

class StackOverflow : public std::exception
{
public:
    const char* what() const noexcept
    {
        return "Stack overflow";
    }
};

class QueueOverflow : public std::exception
{
public:
    const char* what() const noexcept
    {
        return "Queue is full!";
    }
};

#endif // !STACK_OVERFLOW_H

