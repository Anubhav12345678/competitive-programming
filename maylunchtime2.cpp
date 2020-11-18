#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll f[27]={0};
        for(ll i=0;i<s.length();i++)
        {

           s[i]=tolower(s[i]);
            f[s[i]-97]++;
        }

         if(s.length()%2!=0)
         {
             ll c=0;
             for(ll i=0;i<26;i++)
             {
                 if(f[i]%2!=0)
                    c++;
             }
             if(c==1||c==3)
                cout<<"DPS\n";
             else
                cout<<"!DPS\n";
         }
         else
         {
             ll c=0;
             for(ll i=0;i<26;i++)
             {
                 if(f[i]%2!=0)
                    c++;
             }
             if(c==2)
                cout<<"DPS\n";
             else
                cout<<"!DPS\n";
         }

     /*  int c=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a')
                c++;
        }
        if(c==s.length()&&s.length()%2!=0)
            cout<<"DPS\n";
        else
            cout<<"!DPS\n";
*/

    }
}
