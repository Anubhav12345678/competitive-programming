
/*

Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i,
     you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 


*/


class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        bool vis[n];
        memset(vis,0,sizeof(vis));
        queue<int> q;
        q.push(start);
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            int step=arr[cur];
            if(step==0)
                return 1;
            if(cur-step>=0&&!vis[cur-step])
            {
                vis[cur-step]=1;
                q.push(cur-step);
            }
            if(cur+step<n&&!vis[cur+step])
            {
                vis[cur+step]=1;
                q.push(cur+step);
            }
        }
        return 0;
    }
};