//Distorted Palindrome
//Problem Code: ENCD12
#include <bits/stdc++.h>
using namespace std;
/*
A palindrome is a string of letters that is equal to itself when reversed. Given an input string, not necessarily
 a palindrome, compute the number of times you need to swap to transform the string into a palindrome. By swap we
  mean reversing the order of two adjacent symbols. For example, the string "mamad" may be transformed into the 
  palindrome "madam" with 3 swaps:
swap "ad" to get "mamda"
swap "md" to get "madma"
swap "ma" to get "madam"



*/
int main()
{
	string s;
	while(1)
	{
	   // cout<<"s="<<s<<endl;
	    cin>>s;
	    if(s=="0")
	        break;
	    int n=s.length(),odd=0,swap_cnt=0;
	    map<int,int> m;
	    for(int i=0;i<n;i++)
	        m[s[i]]++;

	    for(auto i=m.begin();i!=m.end();i++)
	    {
	        if(i->second%2!=0)
	            odd++;
	    }
	    if(odd>1)
	    {
	        cout<<"Impossible"<<endl;
	    }
	    else
	    {
	        for(int i=0;i<n/2;i++)
    	    {
    	       // cout<<"i="<<i<<endl;
    	        int j=n-1-i;
    	        while(s[j]!=s[i])
    	            j--;
        	   // cout<<"ind="<<ind<<endl;
    	        for(int k=j;k<n-1-i;k++)
    	        {
    	           // cout<<"k="<<k<<endl;
    	            swap(s[k],s[k+1]);
    	            swap_cnt++;
    	        }
    	       // cout<<"swap_cnt="<<swap_cnt<<endl;
    	    }
    	    cout<<swap_cnt<<endl;
	    }
	    
	   // cout<<"odd="<<odd<<endl;
	}
}