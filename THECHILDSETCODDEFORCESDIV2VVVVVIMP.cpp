#include<bits/stdc++.h>
using namespace std;
int arr1[100009];int main()
{int n,k,l=0;
cin>>n>>k;
for(int i=k;i>=1;i--)
{int t=i&-i; // rightmost set bit
// cout<<"t= "<<t<<endl;
if(t<=n)
{n-=t;arr1[l++]=i;
if(n==0)break;}
}
if(n>0)cout<<-1;
else
{printf("%d\n",l);
for(int i=0;i<l;i++)
cout<<arr1[i]<<" ";
}
}
/*
At the children's day, the child came to Picks's house, and messed his house up. Picks was angry at him. A lot of important things were lost, in particular the favorite set of Picks.

Fortunately, Picks remembers something about his set S:

its elements were distinct integers from 1 to limit;
the value of  was equal to sum; here lowbit(x) equals 2 k where k is the position of the first one in the binary representation of x. For example, lowbit(100102) = 102, lowbit(100012) = 12, lowbit(100002) = 100002 (binary representation).
Can you help Picks and find any set S, that satisfies all the above conditions?
*/