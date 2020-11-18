int in[100];
int out[100];
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
       int i,j,k,l,m=requests.size();
        int ans=0,cnt=0;
        for(i=0;i<(1<<m);i++){
            cnt=0;
            memset(in,0,sizeof(in));
            memset(out,0,sizeof(out));
            for(j=0;j<m;j++){
                if(((1<<j)&i)!=0)
                {
                    cnt++;
                    in[requests[j][1]]++;
                    out[requests[j][0]]++;
                }
            }
            int b1=1;
            for(j=0;j<n;j++)
                if(in[j]!=out[j]) b1=0;
            if(b1==1)
            {
                ans = max(ans,cnt);
            }
        }
        
        return ans;
    }
};
/*

We have n buildings numbered from 0 to n - 1. Each building has a number of employees. It's transfer season, and some 
employees want to change the building they reside in.

You are given an array requests where requests[i] = [fromi, toi] represents an employee's request to transfer from
 building fromi to building toi.

All buildings are full, so a list of requests is achievable only if for each building, the net change in employee 
transfers is zero. This means the number of employees leaving is equal to the number of employees moving in. For
 example if n = 3 and two employees are leaving building 0, one is leaving building 1, and one is leaving building
  2, there should be two employees moving to building 0, one employee moving to building 1, and one employee moving to building 2.

Return the maximum number of achievable requests.

 

Example 1:


Input: n = 5, requests = [[0,1],[1,0],[0,1],[1,2],[2,0],[3,4]]
Output: 5
Explantion: Let's see the requests:
From building 0 we have employees x and y and both want to move to building 1.
From building 1 we have employees a and b and they want to move to buildings 2 and 0 respectively.
From building 2 we have employee z and they want to move to building 0.
From building 3 we have employee c and they want to move to building 4.
From building 4 we don't have any requests.
We can achieve the requests of users x and b by swapping their places.
We can achieve the requests of users y, a and z by swapping the places in the 3 buildings.


*/