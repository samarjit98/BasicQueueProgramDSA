#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool isPalindromeQ(queue<char> q)
{
    stack<char> s;
    int sz=q.size();
    char tmp;
    for(int i=1; i<=sz/2; i++)
    {
        tmp=q.front(); q.pop();
        s.push(tmp);
    }

    if(sz%2==1)q.pop();

    int flag=0;

    while(!q.empty())
    {
        if(q.front()==s.top())
        {
            q.pop(); s.pop();
        }
        else
        {
            flag=1; break;
        }
    }

    if(flag==0)return true;
    else return false;
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

    if(isPalindromeQ(q))cout << "Palindromic Queue!" << endl;
    else cout << "Not Palindromic Queue!" << endl;

    return 0;
}
