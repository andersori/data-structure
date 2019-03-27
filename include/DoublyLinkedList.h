#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include <memory>
#include "DoublyNode.h"

using std::shared_ptr;
using std::make_shared;

template<class T>
class DoublyLinkedList
{
	private://only typedef's
		typedef shared_ptr<DoublyNode<T> > pointer_node;
		typedef const T& const_reference;
		typedef T& reference;

	public:
		typedef unsigned int size_type;

		DoublyLinkedList();
		~DoublyLinkedList();

		size_type size() const;
		
		reference get(size_type);
		const_reference get(size_type) const;

		T remove(size_type);
		void push(const_reference);

	private:
		size_type _size;
		pointer_node root;
		pointer_node last;

		pointer_node getNode(size_type);
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	this->_size = 0;
	this->root = nullptr;
	this->last = nullptr;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	while(this->size() != 0)
	{
		this->remove(0);
	}
}

template<class T>
typename DoublyLinkedList<T>::size_type DoublyLinkedList<T>::size() const
{
	return this->_size;
}

template<class T>
typename DoublyLinkedList<T>::reference DoublyLinkedList<T>::get(size_type pos)
{
	pointer_node result = this->getNode(pos);
	if(result != nullptr)
	{
		return result->data;
	}
	else
	{
		throw;
	}
}

template<class T>
typename DoublyLinkedList<T>::const_reference DoublyLinkedList<T>::get(size_type pos) const
{
	pointer_node result = this->getNode(pos);
	if(result != nullptr)
	{
		return result->data;
	}
	else
	{
		throw;
	}
}

template<class T>
T DoublyLinkedList<T>::remove(size_type pos)
{
	pointer_node result = this->getNode(pos);
	if(result != nullptr)
	{
		T data = result->data;
		pointer_node next = result->next;
		pointer_node prev = result->prev;

		if(next != nullptr)
		{
			next->prev = prev;
		}
		if(prev != nullptr)
		{
			prev->next = next;
		}
		
		result = nullptr;

		this->_size--;

		return data;
	}
	else
	{
		throw;
	}
}

template<class T>
void DoublyLinkedList<T>::push(const_reference data)
{
	pointer_node newNode = make_shared<DoublyNode<T> >();
	newNode->data = data;

	if(this->root == nullptr)
	{
		this->root = newNode;
		this->last = root;
	}
	else
	{
		newNode->prev = last;
		this->last->next = newNode;
		this->last = newNode;
	}
	this->_size++;
}

template<class T>
typename DoublyLinkedList<T>::pointer_node DoublyLinkedList<T>::getNode(size_type pos)
{
	if(pos < this->size())
	{
		pointer_node current = this->root;
		for(size_type i = 0; i != pos; i++)
		{
			current = current->next;
		}

		return current;
	}
	else
	{
		return nullptr;
	}
}

#endif