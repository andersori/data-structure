#ifndef ListNode_h
#define ListNode_h

#include <memory>

using std::shared_ptr;

template<class T>
class ListNode
{
	public:
		//constructor and destructor
		ListNode();
		~ListNode();

		//attributes
		T data;
		shared_ptr<ListNode<T> > next;
};

template<class T>
ListNode<T>::ListNode()
{
	this->next = nullptr;
}

template<class T>
ListNode<T>::~ListNode()
{
	this->next = nullptr;
}

#endif