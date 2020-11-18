#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
int main() {
    ll t;
    cin>>t;
    while(t--)
    {
        ll maxi = -1,st=-1;
        string a,b;
        cin>>a>>b;
        ll i=-1,j=0,k,l;
        while(!a.empty())
        {
            if(b.find(a)==string::npos)
            a.pop_back();
            else
            {
                i=b.find(a);
                break;
            }
        }
        if(i==-1)
        cout<<-1<<endl;
        else
        cout<<i<<" "<<a<<endl;
    }
	//code
	return 0;
}