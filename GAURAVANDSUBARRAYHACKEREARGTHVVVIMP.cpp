#include<bits/stdc++.h>
using namespace std;
/*
You are given an array  consisting of  non-negative integers. Now, you need to answer  queries of the following type given an integer K in each query.

You need to find the minimum length L of any subarray of A, such that if all elements of this subarray are represented in binary notation and concatenated to form a binary string, then no of 1's in the resulting string is at least K.  

*/
int solve(int *a,int n,int k)
{
int count[n],i=0,j=0,ans=INT_MAX,sum;
for(i=0;i<n;i++)
count[i]=__builtin_popcount(a[i]);
if(n==1)
{
if(count[0]>=k)
return 1;
else
return -1;
}
i=1;
sum=count[0];
while(i<n)
{
if(count[i]==k)
{
ans=1;
break;
}
else if(count[j]==k)
{
ans=1;
break;
}
else if(sum+count[i]>k)
{
ans=min(ans,(i-j)+1);
sum-=count[j];
j++;
}
else if(sum+count[i]<k)
{
sum+=count[i];
i++;
}
else if(sum+count[i]==k)
{
ans=min(ans,(i-j)+1);
sum+=count[i];
i++;
}
}
if(ans!=INT_MAX)
return ans;
return -1;
}
int main()
{
int n,q;
cin>>n>>q;
int a[n],i;
for(i=0;i<n;i++)
cin>>a[i];
while(q--)
{
int k;
cin>>k;
cout<<solve(a,n,k)<<"\n";
}
return 0;
}