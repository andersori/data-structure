#ifndef Queue_h
#define Queue_h

#include <memory>
#include "LinkedNode.h"


using std::shared_ptr;
using std::make_shared;

template<class T>
class Queue
{
	private:
		int _size;
		shared_ptr<LinkedNode<T> > first;
		shared_ptr<LinkedNode<T> > last;

	public:
		Queue();
		~Queue();

		int size();
		void push(const T&);

		T& front();
		const T& front() const;

		T& back();
		const T& back() const;
		
		T pop();
};

template<class T>
Queue<T>::Queue()
{
	this->_size = 0;
	this->first = nullptr;
	this->last = nullptr;
}

template<class T>
Queue<T>::~Queue()
{
	while(this->_size != 0)
	{
		this->pop();
	}
}

template<class T>
int Queue<T>::size()
{
	return this->_size;
}

template<class T>
void Queue<T>::push(const T& data)
{
	shared_ptr<LinkedNode<T> > newNode = make_shared<LinkedNode<T> >();
	newNode->data = data;

	if(this->first == nullptr)
	{
		this->first = newNode;
		this->last = first;
	}
	else
	{
		this->last->next = newNode;
		this->last = newNode;	
	}
	this->_size++;
}

template<class T>
T& Queue<T>::front()
{
	return this->first->data;
}

template<class T>
const T& Queue<T>::front() const
{
	return this->first->data;
}

template<class T>
T& Queue<T>::back()
{
	return this->last->data;
}

template<class T>
const T& Queue<T>::back() const
{
	return this->last->data;
}

template<class T>
T Queue<T>::pop()
{
	T temp = this->first->data;
	if(this->_size != 0)
	{
		shared_ptr<LinkedNode<T> > next = this->first->next;
		this->first = next;
		this->_size--;
		return temp;
	}
	else
	{
		throw;
	}
}

#endif