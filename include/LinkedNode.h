#ifndef LinkedNode_h
#define LinkedNode_h

#include <memory>

using std::shared_ptr;

template<class T>
class LinkedNode
{
	public:
		LinkedNode();
		~LinkedNode();

		T data;
		shared_ptr<LinkedNode<T> > next;
};

template<class T>
LinkedNode<T>::LinkedNode()
{
	this->next = nullptr;
}

template<class T>
LinkedNode<T>::~LinkedNode()
{
	this->next = nullptr;
}

#endif