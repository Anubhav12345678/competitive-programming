/*

Given an array equations of strings that represent relationships between variables, each string equations[i] has length 4 
and takes one of two different forms: "a==b" or "a!=b".  Here, a and b are lowercase letters (not necessarily different) that
 represent one-letter variable names.

Return true if and only if it is possible to assign integers to variable names so as to satisfy all the given equations.

 

Example 1:

Input: ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.  There is no way 
to assign the variables to satisfy both equations.
Example 2:

Input: ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
Example 3:

Input: ["a==b","b==c","a==c"]
Output: true
Example 4:

Input: ["a==b","b!=c","c==a"]
Output: false
Example 5:

Input: ["c==c","b==d","x!=z"]
Output: true



*/



//better
class Solution {
public:
    vector<int> par;
    int find(int x)
    {
        if(par[x]==x)
            return x;
        return find(par[x]);
    }
    bool equationsPossible(vector<string>& equations) {
        par = vector<int>(26,0);
        int i,j,k,l,n=equations.size();
        for(i=0;i<26;i++)
            par[i]=i;
        for(i=0;i<n;i++)
            if(equations[i][1]=='=')
            {
                int x = find(equations[i][0]-'a');
                int y = find(equations[i][3]-'a');
                if(x!=y)
                    par[y]=x;
            }
        for(i=0;i<n;i++)
        {
            if(equations[i][1]=='!')
            {
              int x = find(equations[i][0]-'a');
              int y = find(equations[i][3]-'a');
                if(x==y)
                    return 0;
            }
        }
        return 1;
            
    }
};







int f[100];
int find(int x)
{
    if(f[x]!=f[f[x]]) f[x]=find(f[x]);
    return f[x];
}
class Solution {
public:
    vector<int> par;
    bool equationsPossible(vector<string>& e) {
        
        int i,j,k,l,n=e.size();
        for(i=0;i<26;i++)
            f[i]=i;
        vector<pair<int,int>> v;
        for(i=0;i<n;i++)
        {
            int e0 = e[i][0]-'a';
            int e3 = e[i][3]-'a';
            int x = find(e0);
            int y = find(e3);
            if(e[i][1]=='!')
                v.push_back({e0,e3});
            else
            {
            int rx = find(e0),ry = find(e3);
            if(rx!=ry)
                f[ry]=rx;
            }
        }
        for(auto x:v)
        {
            if(find(x.first)==find(x.second))
                return 0;
        }
        return 1;
        // vector<int> adj[26];
        
        
    }
};