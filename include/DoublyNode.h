#ifndef DoublyNode_h
#define DoublyNode_h

#include <memory>

using std::shared_ptr;

template<class T>
class DoublyNode
{
	public:
		DoublyNode();
		~DoublyNode();

		T data;
		shared_ptr<DoublyNode<T> > next;
		shared_ptr<DoublyNode<T> > prev;
};

template<class T>
DoublyNode<T>::DoublyNode()
{
	this->next = nullptr;
	this->prev = nullptr;
}

template<class T>
DoublyNode<T>::~DoublyNode()
{
	this->next = nullptr;
	this->prev = nullptr;
}

#endif