#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#include<stack>
vector<ll> solve(vector<ll> &v)
{
	ll n = v.size();
	vector<ll> a(n);
	stack<ll> st;
	st.push(0);
	a[0]=1;
	for(ll i=1;i<n;i++)
	{
		while(!st.empty()&&v[st.top()]<=v[i])
		st.pop();
		a[i] = (st.empty())?(i+1):(i-st.top());
		st.push(i);
	}
	return a;
}
int main() {
	vector<ll> price = { 10, 4, 5, 90, 120, 80 }; 
     ll n = sizeof(price) / sizeof(price[0]); 
    // int S[n]; 
  
    // Fill the span values in array S[] 
    vector<ll> v = solve(price); 
  
    // print the calculated span values 
    for(ll i=0;i<v.size();i++) cout<<"v["<<i<<"] = "<<v[i]<<" "; 
  
    return 0; 
	// your code goes here
	return 0;
}

//me
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<stack>
void solve(int a[],int n)
{
	int i,j,k,l;
	stack<int> st;
	st.push(0);
	int s[n];
	s[0]=1;
	for(i=1;i<n;i++)
	{
		while(!st.empty()&&a[st.top()]<=a[i])
		st.pop();
		s[i] = (st.empty())?(i+1):(i-st.top());
		st.push(i);
	}
	for(i=0;i<n;i++) cout<<s[i]<<" ";
}
int main() {
	int price[] = { 10, 4, 5, 90, 120, 80 }; 
    int n = sizeof(price) / sizeof(price[0]); 
    // int S[n]; 
  
    // Fill the span values in array S[] 
    solve(price, n); 
	// your code goes here
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#include<stack>
void solve(int a[],int n)
{
	int i,j,k,l;
	int s[n];
	stack<int> st;
	st.push(0);
	s[0]=1;
	for(i=1;i<n;i++)
	{
		while(!st.empty()&&a[st.top()]<=a[i])
			st.pop();
		s[i] = (st.empty())?(i+1):(i-st.top());
		st.push(i);
	}
	for(i=0;i<n;i++)
		cout<<"s["<<i<<"] = "<<s[i]<<" ";
}




































