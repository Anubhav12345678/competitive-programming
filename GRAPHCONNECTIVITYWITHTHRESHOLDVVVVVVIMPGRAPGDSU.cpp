class Solution {
public:
    vector<int> par;
    int find(int x)
    {
        if(par[x]==-1) return x;
        return par[x] = find(par[x]);
    }
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        par.resize(n+1,-1);
        int i,j,k,l,m;
        for(i=threshold+1;i<=n;i++)
        {
            j=i;
            while((j+i)<=n)
            {
                int x = find(j);
                int y = find(j+i);
                if(x!=y) par[x]=y;
                j+=i;
            }
        }
        vector<bool> res(queries.size());
        for(i=0;i<queries.size();i++)
        {
            int x = find(queries[i][0]);
            int y = find(queries[i][1]);
            res[i] = (x==y);
        }
        return res;
    }
};
/*

We have n cities labeled from 1 to n. Two different cities with labels x and y are directly connected by a bidirectional road if and only if x and y share a common divisor strictly greater than some threshold. More formally, cities with labels x and y have a road between them if there exists an integer z such that all of the following are true:

x % z == 0,
y % z == 0, and
z > threshold.
Given the two integers, n and threshold, and an array of queries, you must determine for each queries[i] = [ai, bi] if cities ai and bi are connected (i.e. there is some path between them).

Return an array answer, where answer.length == queries.length and answer[i] is true if for the ith query, there is a path between ai and bi, or answer[i] is false if there is no path.

 

Example 1:


Input: n = 6, threshold = 2, queries = [[1,4],[2,5],[3,6]]
Output: [false,false,true]
Explanation: The divisors for each number:
1:   1
2:   1, 2
3:   1, 3
4:   1, 2, 4
5:   1, 5
6:   1, 2, 3, 6
Using the underlined divisors above the threshold, only cities 3 and 6 share a common divisor, so they are the
only ones directly connected. The result of each query:
[1,4]   1 is not connected to 4
[2,5]   2 is not connected to 5
[3,6]   3 is connected to 6 through path 3--6


*/