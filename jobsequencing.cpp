#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct job
{
	ll id;
	ll pr;
	ll dead;
};

ll comparator(job a,job b)
{
	return (a.pr>b.pr);
}

ll schedule(job a[],ll n)
{
	sort(a,a+n,comparator);
	ll result[n];
	bool slot[n];
	ll i;
	for(i=0;i<n;i++)
		slot[i] = false;
	for(i=0;i<n;i++)
	{
       for(j=min(n,a[i].dead)-1;j>=0;j--)
       {
       	if(slot[j]==false)
       	{
       		slot[j] = true;
       		result[j] = i;
       		break;
       	}
       }
	}
	for(i=0;i<n;i++)
		if(slot[i])
			cout<<arr[result[i]].id<<" ";
	cout<<endl;
}

int main()
{
	ll n,ti;
	printf("Enter the jobs profit and their deadline");
	cin>>t;
	while(t--)
	{
		cin>>n;
		job arr[n];
		for(i=0;i<n;i++)
			cin>>arr[i].pr>>arr[i].dead;
		schedule(arr,n);
	}
}
// of practice
#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct job
{
	ll id;
	ll dead;
	ll pr;
};
bool comp(struct job a,struct job b)
{
	return a.pr>b.pr;
}
ll solve(struct job ar[],ll n,ll *p)
{
	ll i,j,sum=0;
	bool slot[n];
	memset(slot,false,sizeof(slot));
	sort(ar,ar+n,comp);
	for(i=0;i<n;i++)
	{
		for(j = min(n,ar[i].dead)-1;j>=0;j--)
		{
			if(slot[j]==false)
			{
				slot[j]=true;
				(*p)++;
				sum+=ar[i].pr;
				break;
			}
		}
	}
	return sum;
}
int main() {
	ll i,j,n,cnt,t;
	cin>>t;
	while(t--)
	{
		cnt=0;
		cin>>n;
		struct job ar[n];
		for(i=0;i<n;i++)
		{
			cin>>ar[i].id;
			cin>>ar[i].dead;
			cin>>ar[i].pr;
		}
		ll x = solve(ar,n,&cnt);
		cout<<cnt<<" "<<x<<endl;
		
	}
	// your code goes here
	return 0;
}