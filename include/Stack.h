#ifndef Stack_h
#define Stack_h

#include <memory>
#include "LinkedNode.h"

using std::shared_ptr;
using std::make_shared;

template<class T>
class Stack
{
	private://only typedef's
		typedef shared_ptr<LinkedNode<T> > pointer_node;
		typedef const T& const_reference;
		typedef T& reference;

	public:
		typedef unsigned int size_type;

		Stack();
		~Stack();
	
		size_type size() const;
		
		reference top();
		const_reference top() const;

		T pop();//Return a copy of the removed element
		void push(const_reference);

	private:
		size_type _size;
		pointer_node root;

};


template<class T>
Stack<T>::Stack()
{
	this->_size = 0;
	this->root = nullptr;
}

template<class T>
Stack<T>::~Stack()
{
	while(this->size() != 0)
	{
		this->pop();
	}
}

template<class T>
typename Stack<T>::size_type Stack<T>::size() const
{
	return this->_size;
}

template<class T>
typename Stack<T>::reference Stack<T>::top()
{
	return this->root->data;
}

template<class T>
typename Stack<T>::const_reference Stack<T>::top() const
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
		this->_size--;
		return data;
	}
	else
	{
		throw;
	}
}

template<class T>
void Stack<T>::push(const_reference data)
{
	pointer_node newNode = make_shared<LinkedNode<T> >();
	newNode->data = data;

	newNode->next = root;
	root = newNode;
	this->_size++;
}

#endif