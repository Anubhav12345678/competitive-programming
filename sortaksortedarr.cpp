#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<queue>
#define pq priority_queue
void sorted(ll a[],ll n,ll k)
{
	pq<ll,vector<ll>,greater<ll>> q(a,a+k+1);//copying first k+1 elements to the priority queue
	ll i,j,index=0;
	for(i=k+1;i<n;i++)
	{
		a[index++] = q.top();
		q.pop();
		q.push(a[i]);
	}
	while(!q.empty())
	{
		a[index++] = q.top();
		q.pop();
	}
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
}
int main() {
	ll a[100001],t,n,i,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(i=0;i<n;i++)
		cin>>a[i];
		sorted(a,n,k);
		cout<<endl;
	}
	
	// your code goes here
	return 0;
}

//me
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue
#include<vector>
#include<queue>
void solve(int a[],int n,int k)
{
	pq <int,vector<int>,greater<int>> q(a,a+k+1);
	int i=0,ind=0,j,l;
	for(i=k+1;i<n;i++)
	{
		a[ind++] = q.top();
		q.pop();
		q.push(a[i]);
	}
	while(!q.empty())
	{
		a[ind++] = q.top();
		q.pop();
	}
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
}
int main() {
	int k = 3; 
    int arr[] = { 2, 6, 3, 12, 56, 8 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    solve(arr, n, k); 
   
    // cout << "Following is sorted array" << endl; 
    // printArray(arr, n); 
   
    return 0; 
	// pq <ll,vector<ll>,greater<ll>> q();
	// your code goes here
	return 0;
}