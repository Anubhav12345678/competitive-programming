// A C++ program for merging overlapping intervals 
#include<bits/stdc++.h> 
using namespace std; 

// An interval has start time and end time 
struct Interval 
{ 
	int start, end; 
}; 

// Compares two intervals according to their staring time. 
// This is needed for sorting the intervals using library 
// function std::sort(). See http://goo.gl/iGspV 
bool compareInterval(Interval i1, Interval i2) 
{ 
	return (i1.start < i2.start); 
} 

// The main function that takes a set of intervals, merges 
// overlapping intervals and prints the result 
void mergeIntervals(Interval arr[], int n) 
{ 
	// Test if the given set has at least one interval 
	if (n <= 0) 
		return; 

	// Create an empty stack of intervals 
	stack<Interval> s; 

	// sort the intervals in increasing order of start time 
	sort(arr, arr+n, compareInterval); 

	// push the first interval to stack 
	s.push(arr[0]); 

	// Start from the next interval and merge if necessary 
	for (int i = 1 ; i < n; i++) 
	{ 
		// get interval from stack top 
		Interval top = s.top(); 

		// if current interval is not overlapping with stack top, 
		// push it to the stack 
		if (top.end < arr[i].start) 
			s.push(arr[i]); 

		// Otherwise update the ending time of top if ending of current 
		// interval is more 
		else if (top.end < arr[i].end) 
		{ 
			top.end = arr[i].end; 
			s.pop(); 
			s.push(top); 
		} 
	} 

	// Print contents of stack 
	cout << "\n The Merged Intervals are: "; 
	while (!s.empty()) 
	{ 
		Interval t = s.top(); 
		cout << "[" << t.start << "," << t.end << "] "; 
		s.pop(); 
	} 
	return; 
} 

// Driver program 
int main() 
{ 
	Interval arr[] = { {6,8}, {1,9}, {2,4}, {4,7} }; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	mergeIntervals(arr, n); 
	return 0; 
} 
// Leetcode
class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        res.clear();
        if(intervals.size()==0)
            return res;
        sort(intervals.begin(),intervals.end(),comp);
        stack<vector<int>> s;
        s.push(intervals[0]);
        int i,j,k,l,n = intervals.size();
        for(j=1;j<n;j++)
        {
            vector<int> v = s.top();
            if(v[1]<intervals[j][0])
            {
                s.push(intervals[j]);
            }
            else if(v[1]<intervals[j][1])
            {
                v[1] = intervals[j][1];
                s.pop();
                s.push(v);
            }
        }
        while(!s.empty())
        {
            vector<int> v = s.top();
            res.push_back(v);
            s.pop();
        }
        return res;
        
    }
};
// same
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#include<stack>
bool comp(vector<int> a,vector<int> b)
{
	return a[0]<b[0];
}
vector<vector<int>> solve(vector<vector<int>> &v)
{
	int i,j,k,l,n = v.size();
	vector<vector<int>> res;
	res.clear();
	if(n==0)
	return res;
	stack<vector<int>> s;
	sort(v.begin(),v.end(),comp);
	s.push(v[0]);
	for(j=1;j<n;j++)
	{
		vector<int> tmp;
		tmp = s.top();
		if(tmp[1]<v[j][0])
		s.push(v[j]);
		else if(tmp[1]<v[j][1])
		{
			tmp[1] = v[j][1];
			s.pop();
			s.push(tmp);
		}
	}
	while(!s.empty())
	{
		res.push_back(s.top());
		s.pop();
	}
	return res;
}
int main() {
	vector<vector<int>> arr =  { {6,8}, {1,9}, {2,4}, {4,7} }; 
    // int n = sizeof(arr)/sizeof(arr[0]); 
    vector<vector<int>> res = solve(arr);
    for(int i=0;i<res.size();i++)
    {
    	for(int j=0;j<res[i].size();j++)
    	cout<<res[i][j]<<" ";
    	cout<<endl;
    }
    return 0; 
	// your code goes here
	return 0;
}
//me..........................................YESSSSSSSSSSSSSSSSSSS
class Solution {
public:
    bool comp(vector<int> a,vector<int> b)
    {
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        if(n==0)
            return res;
        if(n==1)
        {
            res.push_back(intervals[0]);
            return res;
        }
        res.clear();
        vector<vector<int>> a(intervals.begin(),intervals.end());
        int i,j,k,l;
        stack<vector<int>> st;
        sort(a.begin(),a.end());
        st.push(a[0]);
        for(i=1;i<n;i++)
        {
            vector<int> interval = st.top();
            if(interval[1]<a[i][0])
            {
                st.push(a[i]);
            }
            else if(interval[0]<=a[i][0])
            {
                st.pop();
                interval[1] = max(a[i][1],interval[1]);
                st.push(interval);
            }
        }
        while(!st.empty())
        {
            vector<int> v = st.top();
            st.pop();
            res.push_back(v);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

















