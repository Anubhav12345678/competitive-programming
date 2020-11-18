#define inf INT_MAX/2
int cache[101][27][101][101];
class Solution {
public:
    int solve(string &s,int ind,int last,int len,int k){
        if(k<0) return inf;
        if(ind>=s.size()) return 0;
        int ans= cache[ind][last][len][k];
        if(ans!=-1) return ans;
        if((s[ind]-'a')==last){
            int car = (len==1||len==9||len==99);
            // no need to delete
            return cache[ind][last][len][k]=car+solve(s,ind+1,last,len+1,k);
        }
        else{
            return cache[ind][last][len][k]=min(1+solve(s,ind+1,s[ind]-'a',1,k),solve(s,ind+1,last,len,k-1));
        }
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(cache,-1,sizeof(cache));
        // cout<<"ok\n";
        return solve(s,0,26,0,k);
        
    }
};
/*
Run-length encoding is a string compression method that works by replacing consecutive identical
 characters (repeated 2 or more times) with the concatenation of the character and the number marking
  the count of the characters (length of the run). For example, to compress the string "aabccc" we replace
   "aa" by "a2" and replace "ccc" by "c3". Thus the compressed string becomes "a2bc3".

Notice that in this problem, we are not adding '1' after single characters.

Given a string s and an integer k. You need to delete at most k characters from s such that the run-length encoded version of s has minimum length.

Find the minimum length of the run-length encoded version of s after deleting at most k characters.

 

Example 1:

Input: s = "aaabcccd", k = 2
Output: 4
Explanation: Compressing s without deleting anything will give us "a3bc3d" of length 6. Deleting any of the characters 'a' or 'c' would at most decrease the length of the compressed string to 5, for instance delete 2 'a' then we will have s = "abcccd" which compressed is abc3d. Therefore, the optimal way is to delete 'b' and 'd', then the compressed version of s will be "a3c3" of length 4.
*/