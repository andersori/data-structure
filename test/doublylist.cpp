#include <iostream>
#include "../include/DoublyLinkedList.h"

using namespace std;

int main()
{
	DoublyLinkedList<int> lst;
	lst.push(1);
	lst.push(2);
	lst.push(3);
	lst.push(4);
	lst.push(5);
	lst.push(6);
	lst.push(7);
	lst.push(8);
	lst.push(9);
	lst.push(10);

	cout << "Números de 1 a 10 foram inseridos.." << endl;

	cout << "Removido: " << lst.remove(2) << endl;
	cout << "Removido: " << lst.remove(1) << endl;
	cout << "Removido: " << lst.remove(7) << endl;


	cout << "Size: " << lst.getSize() << endl;

	cout << "--Itens--" << endl;
	for(int i = 0; i < lst.getSize(); i++)
	{
		cout << lst.get(i) << endl;
	}

	return 0;
}