class Solution {
public:
    /*

   There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you
 should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish 
all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .

    */
    vector<int> findOrder(int numCourses, vector<vector<int>>& pr) {
        int i,j,k,l,n=pr.size();
        if(n==0)
        {
            vector<int> res(numCourses);
            for(int i=0;i<numCourses;i++)
                res[i]=i;
            return res;
        }
        // if(n==1)
        // {
        //     reverse(pr[0].begin(),pr[0].end());
        //     return pr[0];
        // }
        vector<int> res(numCourses);
        vector<int> cnt(numCourses,0);
        queue<int> q;
        for(i=0;i<n;i++)
            cnt[pr[i][0]]++;
        for(i=0;i<numCourses;i++)
            if(cnt[i]==0)
                q.push(i);
        int numdone=q.size();
        j=0;
        cout<<"numdone = "<<numdone<<endl;
        // cout<<"ok\n";
        while(!q.empty())
        {
            cout<<"ok\n";
            int c = q.front();
            cout<<"c = "<<c<<endl;
            q.pop();
            res[j++]=c;
            cout<<"res["<<j-1<<"]= "<<res[j-1]<<endl;
            cout<<"ok\n";
            for(i=0;i<n;i++)
            {
                // cout<<"ok\ni = "<<i<<endl;
                if(pr[i][1]==c)
                {
                    cnt[pr[i][0]]--;
                    if(cnt[pr[i][0]]==0)
                    {
                        q.push(pr[i][0]);
                        numdone++;
                    }
                }
            }
        }
        if(numdone==numCourses)
            return res;
        else
            return {};
    }
};