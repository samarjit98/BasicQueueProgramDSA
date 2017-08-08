#include <bits/stdc++.h>

using namespace std;

union u
{
    int a;
    char b;
};

struct element
{
    int tag;
    u ele;
};

bool isOperand(char c)
{
    if(c=='*' || c=='+')return true;
    else return false;
}

int evaluate_prefix(string s)
{
    queue<element> q;

    for(int i=0; i<s.size(); i++)
    {
        if(s[i]!=' ')
        {
            if(isOperand(s[i]))
            {
                element e;
                e.tag=0;
                e.ele.b=s[i];
                q.push(e);
            }
            else
            {
                element e;
                e.tag=1;
                e.ele.a=s[i]-'0';
                q.push(e);
            }
        }
    }

    queue<element> q2;

    while(q.size() != 3)
    {
        if(q2.size()>=3)
        {
            element tmp=q2.front(); q2.pop();

            if(tmp.tag==0)
            {
                element tmp1=q2.front(); q2.pop();
                if(tmp1.tag==1)
                {
                    element tmp2=q2.front(); q2.pop();

                    if(tmp2.tag==1)
                    {
                        int b=tmp2.ele.a, c=tmp1.ele.a, ins;
                        if(tmp.ele.b=='*')ins=b*c;
                        else ins=b+c;
                        element e;
                        e.tag=1;
                        e.ele.a=ins;
                        q.push(e);
                    }
                    else
                    {
                        q.push(tmp); q.push(tmp1); q.push(tmp2);
                    }
                }
                else
                {
                    q.push(tmp); q.push(tmp1);
                }
            }
            else
            {
                q.push(tmp);
            }
        }
        else
        {
            element tmp=q.front(); q.pop();
            q2.push(tmp);
        }
    }

    element tmp=q.front(); q.pop();
    element tmp2=q.front(); q.pop();
    element tmp3=q.front(); q.pop();

    if(tmp.ele.b=='*')return tmp2.ele.a*tmp3.ele.a;
    else return tmp2.ele.a+tmp3.ele.a;
}

int main()
{
    string expr;
    getline(cin, expr);
    cout << "ANS: " << evaluate_prefix(expr) << endl;
    return 0;
}
