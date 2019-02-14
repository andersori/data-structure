#include <iostream>
#include "include/Node.h"
#include "include/LinkedList.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    LinkedList<int> lis;

    lis.add(1);
    lis.add(2);
    lis.add(3);
    lis.add(4);
    lis.add(5);
    lis.add(6);

    //lis.printAll();
    //cout << lis.get(6) << endl;
    lis.remove(7);
    lis.printAll();

    return 0;
}
