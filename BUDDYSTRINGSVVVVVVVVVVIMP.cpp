class Solution {
public:
    bool buddyStrings(string A, string B) {
        int i,j,k,l,n=A.size(),m=B.size();
        if(n!=m) return 0;
        if(A==B)
        {
            int cnt[26]={0};
            for(i=0;i<n;i++)
            {
                cnt[A[i]-'a']++;
            }
            for(auto c:cnt)
                if(c>1) return 1;
            return 0;
        }
        else
        {
            int f=-1,l=-1;
            for(i=0;i<n;i++)
            {
                if(A[i]!=B[i])
                {
                    if(f==-1)
                        f=i;
                    else if(l==-1)
                        l=i;
                    else return 0;
                }
            }
            if(l!=-1&&A[f]==B[l]&&B[f]==A[l]) return 1;
            return 0;
        }
    }
};
/*

Given two strings A and B of lowercase letters, return true if you can swap two letters in A so the result is equal to B, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at A[i] and A[j]. For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

 

Example 1:

Input: A = "ab", B = "ba"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'b' to get "ba", which is equal to B.


*/