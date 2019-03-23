#ifndef LinkedList_h
#define LinkedList_h

#include <memory>
#include "ListNode.h"

using std::shared_ptr;
using std::make_shared;

template<class T>
class LinkedList
{
	private:
		unsigned int size;
		shared_ptr<ListNode<T> > root;
		shared_ptr<ListNode<T> > last;

		shared_ptr<ListNode<T> > getNode(unsigned int);

	public:
		LinkedList();
		~LinkedList();

		unsigned int getSize();
		T get(unsigned int);
		T remove(unsigned int);
		void push(T);
};

template<class T>
LinkedList<T>::LinkedList()
{
	this->size = 0;
	this->root = nullptr;
	this->last = nullptr;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	shared_ptr<ListNode<T> > temp;
	while(root != nullptr)
	{
		temp = root;
		root = root->next;
		temp = nullptr;
	}

	this->size = 0;
}

template<class T>
unsigned int LinkedList<T>::getSize()
{
	return this->size;
}

template<class T>
T LinkedList<T>::get(unsigned int pos)
{
	shared_ptr<ListNode<T> > result = this->getNode(pos);
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
T LinkedList<T>::remove(unsigned int pos)
{

    if(pos == 0)
    {
        T data = this->root->data;
        this->root = this->root->next;

        this->size--;
        return data;
    }
    else
    {
        shared_ptr<ListNode<T> > previous = this->getNode(pos-1);
        shared_ptr<ListNode<T> > removed = previous->next;

        if(previous != nullptr)
        {
            T data = removed->data;
            previous->next = removed->next;

            this->size--;
            return data;
        }
        else
        {
            throw;
        }
    }
}

template<class T>
void LinkedList<T>::push(T data)
{
	shared_ptr<ListNode<T> > newNode = make_shared<ListNode<T> >();
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

	this->size++;
}

template<class T>
shared_ptr<ListNode<T> > LinkedList<T>::getNode(unsigned int pos)
{
	shared_ptr<ListNode<T> > temp = this->root;

	for(unsigned int i = 0; i < this->getSize(); i++)
	{
		if(i == pos)
		{
			return temp;
		}
		temp = temp->next;
	}

	return nullptr;
}

#endif
