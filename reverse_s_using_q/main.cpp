#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void reverse_stack(stack<char> &s)
{
    queue<char> q;
    while(!s.empty())
    {
        char tmp=s.top();
        s.pop();
        q.push(tmp);
    }
    while(!q.empty())
    {
        char tmp=q.front();
        q.pop();
        s.push(tmp);
    }
}

int main()
{
    stack<char> s;
    char tmp, ans='y';
    while(ans=='y')
    {
        cout << "Enter element:-"; cin >> tmp;
        s.push(tmp);
        cout << "Enter more:-"; cin >> ans;
    }
    reverse_stack(s);
    while(!s.empty())
    {
        tmp=s.top();
        s.pop();
        cout << tmp << endl;
    }
    return 0;
}
