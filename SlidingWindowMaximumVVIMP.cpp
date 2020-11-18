#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<deque>
// find max in every window of size k in O(n)
int main() {
    ll n,k,a[1000001],i,j;
    deque<ll> q;
    cin>>n>>k;
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<k;i++)
    {
    	while(!q.empty()&&a[i]>=a[q.back()])
    	q.pop_back();
    	q.push_back(i);
    }
    for(;i<n;i++)
    {
    	cout<<a[q.front()]<<" ";
    	while(!q.empty()&&q.front()<(i-k+1))
    	q.pop_front();
    	while(!q.empty()&&a[i]>a[q.back()])
    	q.pop_back();
    	q.push_back(i);
    }
    cout<<a[q.front()]<<" ";
	// your code goes here
	return 0;
}
// me
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0||k==0)
            return {};
        if(n==1||k==1)
            return nums;
        vector<int> res;
        deque<int> q;
        int i,j,l;
        for(i=0;i<k;i++)
        {
            while(!q.empty()&&nums[q.back()]<=nums[i])
                q.pop_back();
            q.push_back(i);
        }
        for(;i<n;i++)
        {
            res.push_back(nums[q.front()]);
            while(!q.empty()&&q.front()<(i-k+1))
                q.pop_front();
             while(!q.empty()&&nums[q.back()]<=nums[i])
                q.pop_back();
            q.push_back(i);
        }
        res.push_back(nums[q.front()]);
        return res;
    }
};