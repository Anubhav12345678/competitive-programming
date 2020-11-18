
/*
Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly 
picks an index in proportion to its weight.

Note:

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.
Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]




*/





vector<int> s;
    Solution(vector<int>& w) {
        for (int ind : w){
            if(s.empty())
                s.push_back(ind);
            else
                s.push_back(ind + s.back());
        }
    }
    
    int pickIndex() {
        int x = s.back();
        int index = rand() % x;
        auto it = upper_bound(s.begin(), s.end(),index);
        return it - s.begin();
    }