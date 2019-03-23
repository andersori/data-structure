#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include <memory>
#include "DoublyNode.h"

using std::shared_ptr;

template<class T>
class DoublyLinkedList
{
	private:
		unsigned int size;
		shared_ptr<DoublyNode<T> > root;
		shared_ptr<DoublyNode<T> > last;

		shared_ptr<DoublyNode<T> > getNode(unsigned int);

	public:
		
}


#endif