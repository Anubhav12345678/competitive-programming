// Author: Huahua
// Author: Huahua
/*
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge
 list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a
  probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go 
from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

 





*/
class Solution {
public:
  double maxProbability(int n, vector<vector<int>>& edges, 
                        vector<double>& succProb, int start, int end) {
    vector<vector<pair<int, double>>> g(n); // u -> {v, -log(w)}
    for (int i = 0; i < edges.size(); ++i) {
      // const double w = -log(succProb[i]);
        double w = succProb[i];
      g[edges[i][0]].emplace_back(edges[i][1], w);
      g[edges[i][1]].emplace_back(edges[i][0], w);
    }
    
     vector<double> d(n,0.0);
      d[start]=1.0;
      queue<int> q;
      q.push(start);
      while(!q.empty())
      {
           int cur = q.front();
          q.pop();
          for(int i=0;i<g[cur].size();i++)
          {
              int to = g[cur][i].first;
              double di = g[cur][i].second;
              if(d[to]<(d[cur]*di))
              {
                  d[to] = d[cur]*di;
                  q.push(to);
              }
          }
      }
      return d[end];
 
    
  }
};