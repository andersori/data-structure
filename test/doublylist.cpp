#include <iostream>
#include "../include/DoublyLinkedList.h"

using namespace std;

int main()
{
	DoublyLinkedList<int> lst;
	lst.push(1);
	lst.push(2);
	lst.push(3);

	cout << "Size: " << lst.getSize() << endl;

	cout << lst.get(1) << endl;

	return 0;
}