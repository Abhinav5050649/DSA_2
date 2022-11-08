#include "bits/stdc++.h"
using namespace std;

int main()
{
    stack<int> s;
    for (int i = 0; i < 5; i++)
    {
        s.push(i);
    }

    cout << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.size() << endl;
    stack<int> s2;

    while (!s.empty())
    {
        s2.push(s.top());        
        cout << s.top() << endl;
        s.pop();
    }

    while (!s2.empty())
    {
        cout << s2.top() << endl;
        s2.pop();
    }
    return 0;
}