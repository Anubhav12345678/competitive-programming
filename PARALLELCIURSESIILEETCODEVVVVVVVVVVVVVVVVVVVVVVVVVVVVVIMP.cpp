class Solution {
public:
    /*
Given the integer n representing the number of courses at some university labeled from 1 to n,
 and the array dependencies where dependencies[i] = [xi, yi]  represents a prerequisite relationship,
  that is, the course xi must be taken before the course yi.  Also, you are given the integer k.

In one semester you can take at most k courses as long as you have taken all the prerequisites for the courses you are taking.

Return the minimum number of semesters to take all courses. It is guaranteed that you can take all courses in some way.





    */
    int minNumberOfSemesters(int n, vector<vector<int>>& d, int k) {
        int i,j,a,b,c,l,m=d.size();
        unordered_map<int,unordered_set<int>> ind,p;
        for(auto it:d)
        {
            ind[it[1]].insert(it[0]);
            p[it[0]].insert(it[1]);
        }
        queue<int> q;
        for(i=1;i<=n;i++)
        {
            if(ind[i].size()==0)
                q.push(i);
        }
        
        int res=0;
        while(!q.empty())
        {
            vector<int> last;
            for(i=0;i<k&&!q.empty();i++)
            {
                int tmp=q.front();
                q.pop();
                last.push_back(tmp);
            }
            
            for(auto it:last)
            {
                for(auto &it2:p[it])
                {
                    ind[it2].erase(it);
                    if(ind[it2].size()==0)
                        q.push(it2);
                }
            }
            res++;
        }
        return res;
    }
};