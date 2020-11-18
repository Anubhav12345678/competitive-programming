#include <bits/stdc++.h>
using namespace std;
#include<vector>
#define pb push_back
void solve(vector<vector<int>> &res,vector<int> &r,vector<int> &a,int sum,int i)
{
	if(sum<0)
	return;
	if(sum==0)
	{
		sort(r.begin(),r.end());
		res.pb(r);
		return;
	}
	while(i<a.size()&&sum-a[i]>=0)
	{
		r.pb(a[i]);
		solve(res,r,a,sum-a[i],i);
		i++;
		r.pop_back();
	}
}
vector<vector<int>> combinationsum(vector<int> &a,int sum)
{
	vector<vector<int>> res;
	vector<int> r;
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	solve(res,r,a,sum,0);
	return res;
}
int main() {
	vector<int> ar; 
    ar.push_back(2); 
    ar.push_back(4); 
    ar.push_back(6); 
    ar.push_back(8); 
    int n = ar.size(); 
  
    int sum = 8; // set value of sum 
    vector<vector<int> > res = combinationsum(ar, sum); 
  
    // If result is empty, then 
    if (res.size() == 0) 
    { 
        cout << "Emptyn"; 
        return 0; 
    } 
  
    // Print all combinations stored in res. 
    for (int i = 0; i < res.size(); i++) 
    { 
        if (res[i].size() > 0) 
        { 
            cout << " ( "; 
            for (int j = 0; j < res[i].size(); j++) 
                cout << res[i][j] << " "; 
            cout << ")"; 
        } 
    } 
	// your code goes here
	return 0;
}