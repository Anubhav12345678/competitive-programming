// C++ program to print all combinations of size 
// k of elements in set 1..n 
#include <bits/stdc++.h> 
using namespace std; 

void makeCombiUtil(vector<vector<int> >& ans, 
	vector<int>& tmp, int n, int left, int k) 
{ 
	// Pushing this vector to a vector of vector 
	if (k == 0) { 
		ans.push_back(tmp); 
		return; 
	} 

	// i iterates from left to n. First time 
	// left will be 1 
	for (int i = left; i <= n; ++i) 
	{ 
		tmp.push_back(i); 
		makeCombiUtil(ans, tmp, n, i + 1, k - 1); 

		// Popping out last inserted element 
		// from the vector 
		tmp.pop_back(); 
	} 
} 

// Prints all combinations of size k of numbers 
// from 1 to n. 
vector<vector<int> > makeCombi(int n, int k) 
{ 
	vector<vector<int> > ans; 
	vector<int> tmp; 
	makeCombiUtil(ans, tmp, n, 1, k); 
	return ans; 
} 

// Driver code 
int main() 
{ 
	// given number 
	int n = 5; 
	int k = 3; 
	vector<vector<int> > ans = makeCombi(n, k); 
	for (int i = 0; i < ans.size(); i++) { 
		for (int j = 0; j < ans[i].size(); j++) { 
			cout << ans.at(i).at(j) << " "; 
		} 
		cout << endl; 
	} 
	return 0; 
} 
// meeeeeeeeeeeeeeeee
class Solution {
public:
    void fill(vector<vector<int>> &res,vector<int> &r,int k,int st,vector<int> &v)
    {
        if(k==0)
        {
           res.push_back(r);
            return;
        }
        for(int i=st;i<v.size();i++)
        {
            r.push_back(v[i]);
            fill(res,r,k-1,i+1,v);
            r.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        int i,j,l;
        vector<int> v;
        v.clear();
        for(i=1;i<=n;i++)
            v.push_back(i);
        vector<vector<int>> res;
        vector<int> r;
        fill(res,r,k,0,v);
        return res;
    }
};
