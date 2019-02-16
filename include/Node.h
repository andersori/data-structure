#ifndef NODE_H
#define NODE_H

#include <memory>

using std::shared_ptr;

template <class T>
class Node
{
    public:
        Node();
        virtual ~Node();


        T getData() const;
        shared_ptr<Node<T> > getNext() const;

        void setData(T);
        void setNext(shared_ptr<Node<T> >);

    protected:
        T data;
        shared_ptr<Node<T> > next;

};

template <class T>
Node<T>::Node()
{
    this->next = nullptr;
}

template <class T>
Node<T>::~Node()
{
    //nothing to do
}

template <class T>
T Node<T>::getData() const
{
    return this->data;
}

template <class T>
void Node<T>::setData(T data)
{
    this->data = data;
}

template <class T>
shared_ptr<Node<T> > Node<T>::getNext() const
{
    return this->next;
}

template <class T>
void Node<T>::setNext(shared_ptr<Node<T> > next)
{
    this->next = next;
}

#endif // NODE_H
