class Solution {
public:
    /*
Q. Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that
 meet the following conditions:

The substrings do not overlap, that is for any two substrings s[i..j] and s[k..l], either j < k or i > l is true.
A substring that contains a certain character c must also contain all occurrences of c.
Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same 
number of substrings, return the one with minimum total length. It can be shown that there exists a unique solution
 of minimum total length.

Notice that you can return the substrings in any order.




Great solution, thanks for posting. I didn't understand why we sort by the end time until I read
 the wikipedia page. Intuitively it makes sense that we would want to greedily select the interval that finishes first.
 Selecting the intervals that start earliest is not an optimal solution, because if the earliest interval
  happens to be very long, accepting it would make us reject many other shorter requests.
    */
    vector<string> maxNumOfSubstrings(string s) {
        int i,j,k,n=s.size();
        vector<int> l(26,INT_MAX);
        vector<int> r(26,INT_MIN);
        for(i=0;i<n;i++){
            l[s[i]-'a'] = min(l[s[i]-'a'],i);
            r[s[i]-'a'] = max(r[s[i]-'a'],i);
        }
        vector<pair<int,int>> v;
        for(i=0;i<26;i++)
        {
            if(l[i]<n){
                int b = l[i];
                int e = r[i];
                for(j=b;j<=e;j++){
                    b= min(b,l[s[j]-'a']);
                    e = max(e,r[s[j]-'a']);
                }
                if(b==l[i])
                    v.push_back({e,b});
            }
        }
      /*
https://en.wikipedia.org/wiki/Interval_scheduling
https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/discuss/744420/C%2B%2BJavaPython-Interval-Scheduling-Maximization-(ISMP)
Great solution, thanks for posting. I didn't understand why we sort by the end time until I read
 the wikipedia page. Intuitively it makes sense that we would want to greedily select the interval that finishes first.
 Selecting the intervals that start earliest is not an optimal solution, because if the earliest interval
  happens to be very long, accepting it would make us reject many other shorter requests.
    */
        sort(v.begin(),v.end());
       int prev=-1;
        vector<string> res;
        for(auto &[e,b]:v){
            if(b>prev){
                res.push_back(s.substr(b,e-b+1));
                prev=e;
            }
        }
        return res;
    }
};