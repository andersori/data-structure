#include <iostream>
#include "../include/Stack.h"

using namespace std;

int main()
{
	Stack<int> sta;

	sta.push(1);
	sta.push(2);
	sta.push(3);
	sta.push(4);

	cout << "Size: " << sta.size() << endl;

	while(sta.size() != 0)
	{
		cout << "Removendo Topo: " << sta.pop() << endl;
	}

	cout << "Size: " << sta.size() << endl;

	return 0;
}