#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<string.h>
int main()
{
    ll n,x,y,i,j,k,l,c=0;
    string s;
    cin>>n>>x>>y;
    cin>>s;
     for(i=0;i<s.size();)
     {
         j=i;
         for(;j<n;j++)
             if(s[j]!='0')
                 break;
         if(j==i)
             i++;
         else
         {
             i=j+1;
             c++;
         }
     }
     // c is the number of grps of consequitive 0's(say c) so we can perform flip or reverse on (c-1) grps by choosing the one with min 
      // cost and in the end when all 0's are together we can at alst use a flip with cost y to get all 1's in the string GOOD QUESTION 
    // cout<<"c = "<<c<<endl;
    if(c==0)
        cout<<0<<endl;
    else
    {
        cout<<(c-1)*min(x,y)+y<<endl;
    }
    
    
    
    
	return 0;
}
