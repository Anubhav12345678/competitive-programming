/*
You are given two strings s1 and s2 of equal length consisting of letters "x" and "y" only. 
Your task is to make these two strings equal to each other. You can swap any two characters that belong to different strings,
 which means: swap s1[i] and s2[j].

Return the minimum number of swaps required to make s1 and s2 equal, or return -1 if it is impossible to do so.



*/




class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int cnt1=0,cnt2=0,cnt3=0,cnt4=0,n=s1.size();
        int i,j,k,l;
        for(i=0;i<n;i++)
        {
            if(s1[i]==s2[i]) continue;
            if(s1[i]=='x') cnt1++;
            else
                cnt2++;
        }
        if((cnt1+cnt2)%2) return -1;
        int res = (cnt1/2)+(cnt2/2);
        cnt1%=2;
        cnt2%=2;
        if(cnt1||cnt2) res+=2;
        return res;
    }
};