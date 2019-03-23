#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include <memory>
#include "DoublyNode.h"

using std::shared_ptr;
using std::make_shared;

template<class T>
class DoublyLinkedList
{
	private:
		int size;
		shared_ptr<DoublyNode<T> > root;//DoublyNode<T>* root; 'Almost the same thing'
		shared_ptr<DoublyNode<T> > last;//DoublyNode<T>* last; 'Almost the same thing'

		shared_ptr<DoublyNode<T> > getNode(int);

	public:
		DoublyLinkedList();
		~DoublyLinkedList();

		int getSize();
		T get(int);
		T remove(int);
		void push(T);
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	this->size = 0;
	this->root = nullptr;
	this->last = nullptr;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	shared_ptr<DoublyNode<T> > temp = root;
	while(root != nullptr)
	{
		root = temp->next;
		temp = root;
	}

	temp = nullptr;
	this->last = nullptr;
	this->size = 0;
}

template<class T>
int DoublyLinkedList<T>::getSize()
{
	return this->size;
}

template<class T>
T DoublyLinkedList<T>::get(int pos)
{
	shared_ptr<DoublyNode<T> > result = this->getNode(pos);
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
T DoublyLinkedList<T>::remove(int pos)
{

}

template<class T>
void DoublyLinkedList<T>::push(T data)
{
	shared_ptr<DoublyNode<T> > newNode = make_shared<DoublyNode<T> >();
	newNode->data = data;

	if(this->root == nullptr)
	{
		this->root = newNode;
		this->last = root;
	}
	else
	{
		newNode->prev = last->prev;
		this->last->next = newNode;
		this->last = newNode;
	}
	this->size++;
}

template<class T>
shared_ptr<DoublyNode<T> > DoublyLinkedList<T>::getNode(int pos)
{
	if(pos > 0 && pos < this->size)
	{
		shared_ptr<DoublyNode<T> > current = this->root;
		for(int i = 0; i != pos; i++)
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