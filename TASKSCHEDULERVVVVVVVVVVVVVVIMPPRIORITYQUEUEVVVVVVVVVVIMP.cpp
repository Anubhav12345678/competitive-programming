/*
You are given a char array representing tasks CPU need to do. It contains
 capital letters A to Z where each letter represents a different task. Tasks
  could be done without the original order of the array. Each task is done in
   one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period
 between two same tasks (the same letter in the array), that is that there must
  be at least n units of time between any two same tasks.

You need to return the least number of units of times that the CPU will take to finish all the given tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.


*/


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto c:tasks) mp[c-'A']++;
        priority_queue<pair<int,int>> pq;
        for(auto it=mp.begin();it!=mp.end();it++){
            pq.push({it->second,it->first});
        }
        
        int ans=0,time=0,cycle=n+1;
        while(!pq.empty()){
            time=0;
            vector<pair<int,char>> v;
            for(int i=0;i<cycle;i++){
                if(!pq.empty()){
                    v.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for(auto t:v){
                if(--t.first)
                    pq.push(t);
            }
            ans+=(!pq.empty())?cycle:time;
        }
        return ans;
    }
};