//IB
int Solution::jump(vector<int> &A) {
    int n=A.size();
    if(n==0||n==1)
    return 0;
    int i=0,j=0,k,l;
    int lvl=0,ps=0,cs=0;
    while(cs<(n-1)){
        lvl++;
        ps=cs;
        for(;j<=ps;j++)
        cs =max(cs,j+A[j]);
        if(cs==ps) return -1;
    }
    return lvl;
}













#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<limits.h>
ll minjumps(ll a[],ll n)
{
	ll i,j,mini=INT_MAX;
	ll jumps[n];
	/*
	here we are filling jumps arr from rigth to left jumps[i] represents minjumps
	to reach from a[i] to a[n-1]
	*/
	jumps[n-1]=0;
	for(i=n-2;i>=0;i--)
	{
		if(a[i]==0)
		jumps[i] = INT_MAX;
		else if(a[i]>=n-i-1)
		jumps[i] = 1;
		else
			
		{
			mini = INT_MAX;
			// following loop checks with all 
            // reachable points and takes  
            // the minimum 
			for(j=i+1;j<n&&j<=i+a[i];j++)
			{
				if(mini>jumps[j])
				mini = jumps[j];
			}
			if(mini!=INT_MAX)
			jumps[i] = mini+1;
			else
			jumps[i] = mini;
		}
		// cout<<i<<" "<<jumps[i]<<endl;
	}
	return jumps[0];
}
int main()
{
	ll a[100005];
	ll n,i;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	cout << "Minimum number of jumps to reach" 
         << " end is " << minjumps(a,n)<<endl; 
    return 0;
	
	
	
	
	
	
}
//LEETCODE ME
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return true;
        if(n==0||nums[0]==0)
            return false;
        int jumps[n];
        memset(jumps,INT_MAX,sizeof(jumps));
        int i,j,k,l;
        jumps[0]=0;
        for(i=1;i<n;i++)
        {
            jumps[i]=INT_MAX;
            for(j=0;j<i;j++)
            {
                if(i<=j+nums[j]&&jumps[j]!=INT_MAX)
                {
                    jumps[i] = min(jumps[i],jumps[j]+1);
                    break;
                }
            }
        }
        return (jumps[n-1]!=INT_MAX);
    }
};