#include<bits/stdc++.h>
using namespace std;
#include<string.h>
#define ll long long
int main()
{
    ll n,q,i,j,k;
    string s;
    cin>>n>>q;
    cin>>s;
    map<char,int> m;
    for(i=0;i<s.size();i++)
    m[s[i]]++;
    while(q--)
    {
        cin>>j;
        if(j==1)
        {
            ll pos;
            char c,cp;
            cin>>pos>>c;
            cp=s[pos-1];
            m[cp]--;
            m[c]++;
            s[pos-1]=c;
        }
        else
        {
            ll cnt[26]={0};
            cin>>k;
            ll ct=0;
            for(i=65;i<=90;i++)
            {
                if(m[i]>0)
                ct+=m[i];
                if(ct>=k)
                break;
            }
            printf("%c\n",i);
        }
    }
    
}








