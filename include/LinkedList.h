#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <memory>
#include <iostream>

using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::endl;

template <class T>
class LinkedList
{
    public:
        LinkedList();
        virtual ~LinkedList();

        virtual unsigned int getSize() const;
        virtual bool add(T);
        virtual T get(unsigned int);
        virtual bool remove(unsigned int);
        virtual void clear();
        virtual void printAll();

    protected:
        unsigned int _size;
        shared_ptr<Node<T> > root;
        shared_ptr<Node<T> > last;
};

template <class T>
LinkedList<T>::LinkedList()
{
    this->_size = 0;
    this->root = nullptr;
    this->last = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <class T>
bool LinkedList<T>::add(T data)
{
    shared_ptr<Node<T> > newNode = make_shared<Node<T> >();
    newNode->setData(data);

    if(root == nullptr)
    {
        root = newNode;
        last = root;
    }
    else
    {
        last->setNext(newNode);
        last = newNode;
    }

    this->_size++;
    return true;
}

template <class T>
void LinkedList<T>::printAll()
{
    shared_ptr<Node<T> > temp = root;
    while(temp != nullptr)
    {
        cout << temp->getData() << endl;
        temp = temp->getNext();
    }
}

template <class T>
void LinkedList<T>::clear()
{

}

template <class T>
unsigned int LinkedList<T>::getSize() const
{
    return _size;
}

template <class T>
T LinkedList<T>::get(unsigned int pos)
{
    unsigned int temp = 0;
    shared_ptr<Node<T> > current = root;

    while(temp < pos && current != nullptr)
    {
        current = current->getNext();
        temp++;
    }

    if(current != nullptr){
        return current->getData();
    }

    throw;
}

template <class T>
bool LinkedList<T>::remove(unsigned int pos)
{
    return false;
}

#endif // LINKEDLIST_H