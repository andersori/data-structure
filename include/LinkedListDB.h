#ifndef LINKEDLISTDB_H
#define LINKEDLISTDB_H

#include "NodeDB.h"

#include <memory>
#include <iostream>

using std::shared_ptr;
using std::make_shared;
using std::cout;
using std::endl;

template <class T>
class LinkedListDB
{
    public:
        LinkedListDB();
        virtual ~LinkedListDB();


        virtual bool push(unsigned int, T);
        virtual bool push_back(T);
        virtual bool push_front(T);
        virtual bool remove(unsigned int);
        virtual T get(unsigned int) const;
        virtual void printAll() const;
        unsigned int getSize() const;

    protected:
        unsigned int _size;
        shared_ptr<NodeDB<T> > root;
        shared_ptr<NodeDB<T> > last;
};

template <class T>
LinkedListDB<T>::LinkedListDB()
{
    this->_size = 0;
    this->root = nullptr;
    this->last = nullptr;
}

template <class T>
LinkedListDB<T>::~LinkedListDB()
{
    //nothing to do
}

template <class T>
bool LinkedListDB<T>::push(unsigned int pos, T data)
{
    if(pos >= 0 && pos < _size)
    {
        if(pos == 0)
        {
            push_front(data);
        }
        else if(pos == (_size -1))
        {
            push_back(data);
        }
        else
        {
            shared_ptr<NodeDB<T> > current = root;

            for(unsigned int i = 0; i < pos; i++)
            {
                current = current->getNext();
            }

            shared_ptr<NodeDB<T> > newNode = make_shared<NodeDB<T> >();
            newNode->setData(data);

            shared_ptr<NodeDB<T> > prev = current->getPrev();
            prev->setNext(newNode);

            newNode->setNext(current);
            newNode->setPrev(prev);
            current->setPrev(newNode);

            _size++;
        }

        return true;

    }

    throw;
}

template <class T>
bool LinkedListDB<T>::push_back(T data)
{
    shared_ptr<NodeDB<T> > newNode = make_shared<NodeDB<T> >();
    newNode->setData(data);

    if(root == nullptr)
    {
        root = newNode;
        last = newNode;
    }
    else
    {
        newNode->setPrev(last);
        last->setNext(newNode);
        last = newNode;
    }

    _size++;
    return true;
}

template <class T>
bool LinkedListDB<T>::push_front(T data)
{
    shared_ptr<NodeDB<T> > newNode = make_shared<NodeDB<T> >();
    newNode->setData(data);

    if(root == nullptr)
    {
        root = newNode;
        last = newNode;
    }
    else
    {
        newNode->setNext(root);
        root->setPrev(newNode);
        root = newNode;
    }

    _size++;
    return true;
}

template <class T>
bool LinkedListDB<T>::remove(unsigned int pos)
{
    if(pos >=0 && pos < _size)
    {
        shared_ptr<NodeDB<T> > current = root;

        for(unsigned int i = 0; i < pos; i++)
        {
            current = current->getNext();
        }

        shared_ptr<NodeDB<T> > prev = current->getPrev();
        shared_ptr<NodeDB<T> > next = current->getNext();

        prev->setNext(next);
        next->setPrev(prev);

        return true;
    }

    throw;
}

template <class T>
T LinkedListDB<T>::get(unsigned int pos) const
{
    if(pos >=0 && pos < _size)
    {
        shared_ptr<NodeDB<T> > current = root;

        for(unsigned int i = 0; i < pos; i++)
        {
            current = current->getNext();
        }

        return current->getData();
    }

    throw;
}

template <class T>
void LinkedListDB<T>::printAll() const
{
    shared_ptr<NodeDB<T> > current = root;

    for(unsigned int i = 0; i < _size; i++)
    {
        cout << current->getData() << endl;
        current = current->getNext();
    }
}

template <class T>
unsigned int LinkedListDB<T>::getSize() const
{
    return _size;
}

#endif // LINKEDLISTDB_H
