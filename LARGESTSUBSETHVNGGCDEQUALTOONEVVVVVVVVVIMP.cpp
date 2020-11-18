//Given an array A  of size N , find size of largest subset such that gcd  of every pair possible in subset is equal to 1.

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

bool isclear(vector<int> v,int a)
{
    for(int i=0;i<v.size();i++)
        if(__gcd(a,v[i])!=1)
            return false;
    
    return true;
}

int main() {
    int n;
    cin>>n;
    
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
     sort(nums.begin(),nums.end());
    // for(int i=0;i<n;i++)
    //     cout<<nums[i]<<" ";
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int c=1;
        vector<int> v;
        v.push_back(nums[i]);
        for(int j=0;j<n;j++)
        {
            if(j!=i&&isclear(v,nums[j]))
            {
                v.push_back(nums[j]);
                c++;
            }
        }
        // cout<<"\n\n\n";
        // for(i=0;i<v.size();i++)
        //     cout<<v[i]<<" ";
        // cout<<"\n\n\n";
        ans=max(ans,c);
    }
    cout<<ans<<endl;
    
}