/*
Suppose there is a circle. There are n petrol pumps on that circle. You are given two sets of data.
The amount of petrol that every petrol pump has.
Distance from that petrol pump to the next petrol pump.
Calculate the first point from where a truck will be able to complete the circle (The truck will stop at each petrol pump and it has 
infinite capacity). Expected time complexity is O(n). Assume for 1-litre petrol, the truck can go 1 unit of distance.

For example, let there be 4 petrol pumps with amount of petrol and distance to next petrol pump value pairs as {4, 6}, {6, 5}, {7, 3} 
and {4, 5}. The first point from where the truck can make a circular tour is 2nd petrol pump. Output should be “start = 1” 
(index of 2nd petrol pump).



*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#include<map>
#define pb push_back
#define mp make_pair
int solve(vector<vector<int>> petrol)
{
	int n = petrol.size();
	int st=0,en=1;
	int cur = petrol[st][0]-petrol[st][1];
	while(en!=st||cur<0)
	{
		while(cur<0&&en!=st)
		{
			
			cur-= petrol[st][0]-petrol[st][1];
			st = (st+1)%n;
			if(st==0)
			return -1;
		}
		cur+=petrol[en][0]-petrol[en][1];
		en = (en+1)%n;
	}
	return st;
	
}
int main() {
	
	vector<vector<int>> petrol;
	petrol = {{6, 4}, {3, 6}, {7, 3}};
	
	cout<<solve(petrol);
	// your code goes here
	return 0;
}