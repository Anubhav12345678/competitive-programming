// BOOLEAN PARENTHESIZATION
#include<bits/stdc++.h>
using namespace std;
#define ll long long
// A string is given with 'T(true)','F(false)','&','|','^' these 5 chars 
// we need to tell the nuber of ways to put parenthesis so that expression evaluates to true
// this is recursive approach
int solve(string s,int i,int j,bool istrue)
{
	if(i>j)
    return 0;
    if(i==j)
    {
    	if(istrue==true)
    		return s[i]=='T';
    	else
    		return s[i]=='F';
    }
    int ans=0;
    for(int k=i+1;k<=j-1;k++)
    {
    	int lt = solve(s,i,k-1,true);// number of ways left expression evaluates to true
    	int lf = solve(s,i,k-1,false);// number of ways left expression evaluates to false
    	int rt = solve(s,k+1,j,true);// number of ways right expression evaluates to true
    	int rf = solve(s,k+1,j,false);// number of ways right expression evaluates to false
        if(s[i]=='&')
        {
        	if(istrue==true)
        	{
        		ans+=lt*rt;
        	}
        	else
        		ans+=lt*rf+lf*rt+lf*rf;
        }
        else if(s[i]=='|')
        {
        	if(istrue==true)
        	{
        		ans+=lt*rt+lt*rf+lf*rt;
        	}
        	else
        		ans+=lf*rf;
        }
        else if(s[i]=='^')
        {
        	if(istrue==true)
        	{
        		ans+=lt*rf+lf*rt;
        	}
        	else
        		ans+=lf*rf+lt*rt;
        }
    }
    return ans;
}








