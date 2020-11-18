#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string str)
{
    int sz = str.size();
    int ss = sz/2,ck=1;
    for(int i=0; i<ss; i++)
        if(str[i]!=str[sz-i])
        {
            ck=0;
            break;
        }

    if(ck)
        return 1;
    return 0;
}

void solve()
{
    string str;
    cin>>str;
    int sz = str.size(),ck=0;
    if(str=="10")
    {
        cout<<9<<endl;
        return;
    }
    if(sz==1)
    {
        cout<<str<<endl;
        return;
    }
    int cntt=0;
    for(int i=1; i<sz; i++)
    {
        if(str[i]=='0')
            cntt++;
    }
    if(cntt==(sz-1))
    {
        if(str[0]=='1')
        {
            for(int i=1; i<sz; i++)
            {
                cout<<9;
            }
            cout<<endl;
            return;
        }
        else
            str[0] = str[0]-1;
        cout<<str[0];
        for(int i=1; i<sz; i++)
        {
            cout<<9;
        }
        cout<<endl;
        return;
    }
    int pos=1000000,i=sz-1;
    while(str[i]=='9' && i>=0)
    {
        pos=i;
        i--;
    }
    if(pos==0)
    {
        cout<<str<<endl;
        return;
    }
    for(int i=0; i<sz; i++)
    {
        if(ck || i>=pos)
            cout<<9;
        else
        {
            if((str[i]=='1' && i==0) || str[i]=='0' || i+1==pos)
            {
                cout<<str[i];
            }
            else
            {
                ck=1;
                if(i<sz-1)
                    str[i]--;
                cout<<str[i];
            }
        }
    }
    cout<<endl;
    return;
}

int main()
{
    int tst;
    cin>>tst;
    while(tst--)
        solve();
    return 0;
}

