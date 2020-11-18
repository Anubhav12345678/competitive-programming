class Solution {
public:
    bool isScramble(string s1, string s2) {
        int sSize = s1.size(), len, i, j, k;
        if(0==sSize) return true;
        if(1==sSize) return s1==s2;
        bool isS[sSize+1][sSize][sSize];

        for(i=0; i<sSize; ++i)
            for(j=0; j<sSize; ++j)
                isS[1][i][j] = s1[i] == s2[j];
                
        for(len=2; len <=sSize; ++len)
            for(i=0; i<=sSize-len; ++i)
                for(j=0; j<=sSize-len; ++j)
                {
                    isS[len][i][j] = false;
                        for(k=1; k<len && !isS[len][i][j]; ++k)
                        {
                            isS[len][i][j] = isS[len][i][j] || (isS[k][i][j] && isS[len-k][i+k][j+k]);
                            isS[len][i][j] = isS[len][i][j] || (isS[k][i+len-k][j] && isS[len-k][i][j+k]);
                        }
                }
        return isS[sSize][0][0];            

    }
}; 


int Solution::isScramble(const string A, const string B) {
    int i,j,k,l,n=A.size();
    if(A.compare(B)==0)
    return 1;
    vector<int> cnt(26,0);
    for(i=0;i<n;i++){
        cnt[A[i]-'a']++;
        cnt[B[i]-'a']--;
    }
    for(i=0;i<26;i++)
    if(cnt[i]!=0) return 0;
    for(i=1;i<n;i++){
        if(isScramble(A.substr(0,i),B.substr(0,i))&&isScramble(A.substr(i),B.substr(i)))
        return 1;
        if(isScramble(A.substr(0,i),B.substr(n-i))&&isScramble(A.substr(i),B.substr(0,n-i)))
        return 1;
    }
    return 0;
}
/*
Given a string A, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of A = “great”:


    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
 
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that “rgeat” is a scrambled string of “great”.



*/