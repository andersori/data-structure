#include <iostream>
#include "include/LinkedList.h"
#include "include/Stack.h"

using namespace std;

int main()
{
    LinkedList<Stack<int> > lst_sta;
    
    for(int i = 0; i < 5; i++)
    {
        Stack<int> st;
        for(int j = 0; j < 10; j++)
        {
            st.push((i+1)*j);
        }
        lst_sta.push(st);
    }


    for(int i = 0; i < lst_sta.size(); i++)
    {
        Stack<int> temp = lst_sta.remove(0);
        for(int j = 0; j < 10; j++)
        {
            cout << lst_sta.pop();
        }
        cout << endl;
    }

    return 0;
}
