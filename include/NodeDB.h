#ifndef NODEDB_H
#define NODEDB_H

#include <memory>

using std::shared_ptr;

template <class T>
class NodeDB
{
    public:
        NodeDB();
        virtual ~NodeDB();

        T getData() const;
        shared_ptr<NodeDB<T> > getPrev() const;
        shared_ptr<NodeDB<T> > getNext() const;

        void setData(T);
        void setPrev(shared_ptr<NodeDB<T> >);
        void setNext(shared_ptr<NodeDB<T> >);

    protected:
        T data;
        shared_ptr<NodeDB<T> > prev;
        shared_ptr<NodeDB<T> > next;
};

template <class T>
NodeDB<T>::NodeDB()
{
    this->prev = nullptr;
    this->next = nullptr;
}

template <class T>
NodeDB<T>::~NodeDB()
{
    //nothing to do
}

template <class T>
T NodeDB<T>::getData() const
{
    return data;
}

template <class T>
shared_ptr<NodeDB<T> > NodeDB<T>::getPrev() const
{
    return prev;
}

template <class T>
shared_ptr<NodeDB<T> > NodeDB<T>::getNext() const
{
    return next;
}

template <class T>
void NodeDB<T>::setData(T data)
{
    this->data = data;
}

template <class T>
void NodeDB<T>::setPrev(shared_ptr<NodeDB<T> > prev)
{
    this->prev = prev;
}

template <class T>
void NodeDB<T>::setNext(shared_ptr<NodeDB<T> > next)
{
    this->next = next;
}

#endif // NODEDB_H
