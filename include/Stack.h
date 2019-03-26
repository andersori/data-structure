#ifndef Stack_h
#define Stack_h

#include <memory>
#include "LinkedNode.h"

using std::shared_ptr;
using std::make_shared;

template<class T>
class Stack
{
	private:
		int size;
		shared_ptr<LinkedNode<T> > root;

	public:
		Stack();
		~Stack();
	
		int getSize();
		T top();
		T pop();
		void push(T);

};


template<class T>
Stack<T>::Stack()
{
	this->size = 0;
	this->root = nullptr;
}

template<class T>
Stack<T>::~Stack()
{
	while(this->size != 0)
	{
		this->pop();
	}
}

template<class T>
int Stack<T>::getSize()
{
	return this->size;
}

template<class T>
T Stack<T>::top()
{
	return this->root->data;
}

template<class T>
T Stack<T>::pop()
{
	if(root != nullptr)
	{
		T data = this->root->data;
		this->root = this->root->next;
		this->size--;
		return data;
	}
	else
	{
		throw;
	}
}

template<class T>
void Stack<T>::push(T data)
{
	shared_ptr<LinkedNode<T> > newNode = make_shared<LinkedNode<T> >();
	newNode->data = data;

	newNode->next = root;
	root = newNode;
	this->size++;
}

#endif