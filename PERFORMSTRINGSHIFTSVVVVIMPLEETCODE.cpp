


/*
You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

direction can be 0 (for left shift) or 1 (for right shift). 
amount is the amount by which string s is to be shifted.
A left shift by 1 means remove the first character of s and append it to the end.
Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
Return the final string after all operations.

 

Example 1:

Input: s = "abc", shift = [[0,1],[1,2]]
Output: "cab"
Explanation: 
[0,1] means shift to left by 1. "abc" -> "bca"
[1,2] means shift to right by 2. "bca" -> "cab"



*/



class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int i,j,k,l;
        string st = s+s;
        string news = s;
        int n = s.size();
        int m = shift.size();
        for(i=0;i<m;i++)
        {
            if(shift[i][0]==0)// leftshift
            {
                k = shift[i][1];
                k=k%n;
                if(k!=0)
                {
                    news = news.substr(k)+news.substr(0,k);
                }
            }
            else
            {
                k = shift[i][1];
                k=k%n;
                k=n-k;
                if(k!=0)
                {
                    news = news.substr(k)+news.substr(0,k);
                }
            }
        }
        return news;
        
    }
};