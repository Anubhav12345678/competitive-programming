#include "solution.hpp"
using namespace std;

static int  mod = 1e9+7;
class Solution {
    public:
    int K;
    vector<vector<vector<int>>> memo;
    int dp(string &s,int k,int start,int tight,char prev){
        if(k<0)
        return 0;
        if(start==s.size())
        return 1;
        if(memo[start][k+1][tight]!=-1) return memo[start][k+1][tight]%mod;
        memo[start][k+1][tight]=0;
        for(char c='a';c<='z';c++){
            if(tight&&c>s[start]) break;
            if(!k&&c==prev) continue;
            memo[start][k+1][tight] = (memo[start][k+1][tight]+dp(s,(c==prev?(k-1):(K-1)),start+1,tight&&c==s[start],c))%mod;
        }
        
        return memo[start][k+1][tight];
    }
    int solve(string s, int k) {
        K=k;
        memo = vector<vector<vector<int>>>(s.size(),vector<vector<int>>(k+1,vector<int>(2,-1)));
        return dp(s,k-1,0,1,'.');
        // Write your code here
    }
};
/*
Given a string s of lowercase letters and an integer k, return the number of strings of equal size as s
 (only consisting of lowercase letters) that are lexicographically smaller or equal to s and have at most 
 k consecutive equal characters.

Mod the result by 10 ** 9 + 7.



*/