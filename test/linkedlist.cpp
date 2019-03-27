#include <iostream>
#include "../include/LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> lst;
    lst.push(1);
    lst.push(2);
    lst.push(3);

    cout << "Tamanho: " << lst.size() << endl;

	cout << "--Itens--" << endl;
    cout << lst.get(0) << endl;
    cout << lst.get(1) << endl;
    cout << lst.get(2) << endl;

    return 0;
}
