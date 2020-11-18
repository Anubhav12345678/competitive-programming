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
       for(j=(a[i].dead)-1;j>=0;j--)
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