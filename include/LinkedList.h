#ifndef LinkedList_h
#define LinkedList_h

#include <memory>
#include "LinkedNode.h"

using std::shared_ptr;
using std::make_shared;

template<class T>
class LinkedList
{
	private://only typedef's
		typedef shared_ptr<LinkedNode<T> > pointer_node;
		typedef const T& const_reference;
		typedef T& reference;

	public:
		typedef unsigned int size_type;

		LinkedList();
		~LinkedList();

		size_type size() const;
		
		reference get(size_type);
		const_reference get(size_type) const;

		T remove(size_type);//Return a copy of the removed element
		void push(const_reference);

	private:
		size_type _size;
		pointer_node root;
		pointer_node last;

		pointer_node get_node(size_type);
};

template<class T>
LinkedList<T>::LinkedList()
{
	this->_size = 0;
	this->root = nullptr;
	this->last = nullptr;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	while(this->size() != 0)
	{
		this->remove(0);
	}
}

template<class T>
typename LinkedList<T>::size_type LinkedList<T>::size() const
{
	return this->_size;
}

template<class T>
typename LinkedList<T>::reference LinkedList<T>::get(size_type pos)
{
	pointer_node result = this->get_node(pos);

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
typename LinkedList<T>::const_reference LinkedList<T>::get(size_type pos) const
{
	pointer_node result = this->get_node(pos);

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
T LinkedList<T>::remove(size_type pos)
{

    if(pos == 0)
    {
        T data = this->root->data;
        this->root = this->root->next;

        this->_size--;
        return data;
    }
    else
    {
        pointer_node previous = this->get_node(pos-1);
        pointer_node removed = previous->next;

        if(previous != nullptr)
        {
            T data = removed->data;
            previous->next = removed->next;

            this->_size--;
            return data;
        }
        else
        {
            throw;
        }
    }
}

template<class T>
void LinkedList<T>::push(const_reference data)
{
	pointer_node newNode = make_shared<LinkedNode<T> >();
	newNode->data = data;

	if(this->root == nullptr)
	{
		root = newNode;

		last = root;
	}
	else
	{
		last->next = newNode;
		last = newNode;
	}

	this->_size++;
}

template<class T>
typename LinkedList<T>::pointer_node LinkedList<T>::get_node(size_type pos)
{
	if(pos < this->size())
	{
		pointer_node temp = this->root;

		for(size_type i = 0; i < this->size(); i++)
		{
			if(i == pos)
			{
				return temp;
			}
			temp = temp->next;
		}
	}

	return nullptr;
}

#endif
