class Solution {
public:
    string removeDuplicates(string s, int k) {
        int i,j,l,n,m;
        n=s.size();
        vector<pair<int,char>> st = {{0,'#'}};
        for(auto c:s){
            if(st.back().second!=c){
                st.push_back({1,c});
            }
            else if(++st.back().first==k)
                st.pop_back();
        }
        string res="";
        for(i=1;i<st.size();i++){
            int x = st[i].first;
            char c = st[i].second;
            while(x--)
                res+=c;
        }
        
        return res;
    }
};
/*
Given a string s, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made.

It is guaranteed that the answer is unique.

 

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
*/