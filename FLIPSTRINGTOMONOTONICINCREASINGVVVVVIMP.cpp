/*
A string of '0's and '1's is monotone increasing if it consists of some number of '0's (possibly 0), followed by some number of '1's (also possibly 0.)

We are given a string S of '0's and '1's, and we may flip any '0' to a '1' or a '1' to a '0'.

Return the minimum number of flips to make S monotone increasing.

 

Example 1:

Input: "00110"
Output: 1
Explanation: We flip the last digit to get 00111.



*/



class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int i,j,k,l,n=s.size();
        i=0,j=0;
        // int ans=0;
        // string p = s;
        int p[n+1];
        p[0]=0;
        // sort(p.begin(),p.end());
        for(i=0;i<n;i++)
        {
            p[i+1] = p[i]+((s[i]=='1')?1:0);
        }
        p[0]=0;
        int ans=INT_MAX;
        for(i=0;i<=n;i++)
        {
            cout<<p[i]<<" "<<(n-i-(p[n]-p[i]))<<endl;
            ans = min(ans,p[i]+(n-i-(p[n]-p[i])));
        }
        return ans;
    }
};