#include <iostream>
#include "include/Node.h"
#include "include/LinkedList.h"
#include "include/LinkedListDB.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    LinkedListDB<int> lis;

    lis.push_back(1);
    lis.push_back(2);
    lis.push_back(4);
    lis.push_front(28);

    lis.push(2, 312);

    //lis.printAll();
    //cout << lis.get(6) << endl;
    //lis.remove(7);
    lis.printAll();

    //cout << " mekd " << lis.get(4) << endl;

    return 0;
}
