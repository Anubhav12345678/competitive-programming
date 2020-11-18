//leetcode
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i,j,k,l,n=gas.size();
        if(n==1)
            return gas[0]>=cost[0]?0:-1;
        int st=0,en=0;
        en=1;
        int curpet = gas[st]-cost[st];
        while(st!=en||curpet<0)
        {
            while(st!=en&&curpet<0)
            {
                curpet-=gas[st]-cost[st];
                st = (st+1)%n;
                if(st==0)
                    return -1;
            }
            curpet+=gas[en]-cost[en];
            en= (en+1)%n;
        }
        return st;
    }
};



//INTERVIEWBIT
int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    int st=0,en=1,i,j,k,l,n=gas.size();
    int curpetrol=gas[st]-cost[st];
    while(st!=en||curpetrol<0)
    {
        while(curpetrol<0&&st!=en)
        {
            curpetrol-=gas[st]-cost[st];
            st = (st+1)%n;
            if(st==0)
            return -1;
        }
        curpetrol+=gas[en]-cost[en];
        en = (en+1)%n;;
    }
    return st;
}
/*

Given two integer arrays A and B of size N.
There are N gas stations along a circular route, where the amount of gas at station i is A[i].

You have a car with an unlimited gas tank and it costs B[i] of gas to travel from station i
to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the minimum starting gas station’s index if you can travel around the circuit once, otherwise return -1.

You can only travel in one direction. i to i+1, i+2, … n-1, 0, 1, 2.. Completing the circuit means starting at i and
ending up at i again.





*/