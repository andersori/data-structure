#ifndef Queue_h
#define Queue_h

#include <memory>
#include "LinkedNode.h"


using std::shared_ptr;
using std::make_shared;

template<class T>
class Queue
{
	private://only typedef's
		typedef shared_ptr<LinkedNode<T> > pointer_node;
		typedef const T& const_reference;
		typedef T& reference;

	public:
		typedef unsigned int size_type;

		Queue();
		~Queue();

		size_type size() const;
		void push(const_reference);

		reference front();
		const_reference front() const;

		reference back();
		const_reference back() const;
		
		T pop();//Return a copy of the removed element

	private:
		size_type _size;
		pointer_node first;
		pointer_node last;
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
	while(this->size() != 0)
	{
		this->pop();
	}
}

template<class T>
typename Queue<T>::size_type Queue<T>::size() const
{
	return this->_size;
}

template<class T>
void Queue<T>::push(const_reference data)
{
	pointer_node newNode = make_shared<LinkedNode<T> >();
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
typename Queue<T>::reference Queue<T>::front()
{
	return this->first->data;
}

template<class T>
typename Queue<T>::const_reference Queue<T>::front() const
{
	return this->first->data;
}

template<class T>
typename Queue<T>::reference Queue<T>::back()
{
	return this->last->data;
}

template<class T>
typename Queue<T>::const_reference Queue<T>::back() const
{
	return this->last->data;
}

template<class T>
T Queue<T>::pop()
{
	T temp = this->first->data;
	if(this->_size != 0)
	{
		pointer_node next = this->first->next;
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