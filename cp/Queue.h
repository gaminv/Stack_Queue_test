#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue
{
public:
	virtual ~Queue() {}
	virtual void enQueue(const T& e) = 0; // Adding an item to the queue
	virtual T deQueue() = 0; // Removing the top element
	virtual bool isEmpty() = 0; // Checking the queue for emptiness
};

#endif // !QUEUE_H