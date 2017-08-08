#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverse_queue(queue<char> &q)
{
    stack<char> s;
    while(!q.empty())
    {
        char tmp=q.front();
        q.pop();
        s.push(tmp);
    }
    while(!s.empty())
    {
        char tmp=s.top();
        s.pop();
        q.push(tmp);
    }
}

int main()
{
    queue<char> q;
    char tmp, ans='y';

    while(ans=='y')
    {
        cout << "Enter element:-"; cin >> tmp;
        q.push(tmp);
        cout << "Enter more:-"; cin >> ans;
    }

    reverse_queue(q);

    while(!q.empty())
    {
        char tmp=q.front();
        q.pop();
        cout << tmp << endl;
    }
    return 0;
}
