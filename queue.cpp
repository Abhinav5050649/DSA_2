#include "bits/stdc++.h"
using namespace std;

//STL

int main()
{
    /*
    queue<int> gq;
    for (int i = 0; i < 4; i++)
    {
        gq.push(i);
    }

    cout << "Front: " <<gq.front() << endl << "Back: "<< gq.back() << endl;
    cout << "Size: " << gq.size() << endl << endl;

    while (!gq.empty())
    {
        cout << gq.back() << endl;
        gq.pop();
    }
    */

   priority_queue<char> gq;
   string s = "()";
   for (int i = 0; i < 6; i++)
   {
       gq.push(s[i]);
   }

    string ans = "";
   while (!gq.empty())
   {
       ans += gq.top();
       gq.pop();
   }

    cout << ans << endl;
    bool check = true;
   for (int i = 0; i < 6; i+= 2)
   {
       if (ans[i] == '}' && ans[i + 1] == '{')
       {
           continue;
       }else if (ans[i] == ']' && ans[i + 1] == '[')
       {
          continue; 
       }
       else if (ans[i] == ')' && ans[i + 1] == '(')
       {
           continue;
       }
       else{
           check = false;
           break;
       }
    }
    cout << check << endl;
    return 0;
}