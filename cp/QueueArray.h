#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include "Queue.h"
#include "StackOverflow.h"
#include "StackUnderflow.h"
#include "WrongStackSize.h"

template <class T>
class QueueArray : public Queue<T> {
private:
    int size = 0;
    int head = -1;
    int tail = -1;
    T* queueArray;

public:
    QueueArray(int size) : size(size), head(-1), tail(-1) {
        if (size <= 0) {
            throw WrongQueueSize();
        }
        queueArray = new T[size];
    }

    QueueArray(const QueueArray<T>& src) = delete;
    QueueArray(QueueArray<T>&& src) = delete;
    QueueArray& operator=(const QueueArray<T>& src) = delete;
    QueueArray& operator=(QueueArray<T>&& src) = delete;

    ~QueueArray() {
        delete[] queueArray;
    }

    void enQueue(const T& element) {
        if (head == -1) {
            head = 0;
        }
        if (tail == size - 1) {
            throw QueueOverflow();
        }
        tail++;
        queueArray[tail] = element;
    }

    T deQueue() {
        if (isEmpty()) {
            throw QueueUnderflow();
        }
        T item = queueArray[head];
        head++;
        if (head > tail) {
            head = tail = -1;
        }
        return item;
    }

    bool isEmpty() {
        return head == -1 and tail == -1;
    }
};
#endif // !QUEUE_ARRAY_H