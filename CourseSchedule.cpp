vector<int> indegree(numCourses, 0);
    
    for(int i=0; i<prerequisites.size(); i++){
        indegree[prerequisites[i][0]]++;
    }
    
    queue<int> q;
    for(int i=0; i<numCourses; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    
    int count=0;
    if(q.size()==0) return false;
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        
        for(int i=0; i<prerequisites.size(); i++){
            if(prerequisites[i][1]==u){
                indegree[prerequisites[i][0]]--;
                if(indegree[prerequisites[i][0]]==0){
                    q.push(prerequisites[i][0]);
                }
            }
        }
        count++;
    }
    if(count!=numCourses) return false;
    return true;
    //me VVVIMP
    class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        int n = p.size();
        int N = numCourses;
        
        int i,j,k,l,u=0,t=0,c=0;
        vector<int> cnt(N,0);
        vector<vector<int>> mat(N);
        queue<int> q;
        for(auto it: p)
        {
            cnt[it[0]]++;
            mat[it[1]].push_back(it[0]);
        }
        for(i=0;i<N;i++)
            if(cnt[i]==0) q.push(i);
        while(!q.empty())
        {
            c++;
            int x = q.front();
            q.pop();
            for(int  p:mat[x])
            {
                cnt[p]--;
                if(cnt[p]==0)
                    q.push(p);
            }
        }
        return c==N;
        
        
    }
};