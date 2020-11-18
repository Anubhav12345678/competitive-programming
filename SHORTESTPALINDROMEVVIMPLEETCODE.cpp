
/*

Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the
 shortest palindrome you can find by performing this transformation.

Example 1:

Input: "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: "abcd"
Output: "dcbabcd"



*/



class Solution {
public:
    string shortestPalindrome(string s) {
        cout << "s: " << s << endl;
        int len = s.size();
        int l = 0;
        int r = len-1;
        // Find the window till where for matching character count is frequency of 2
        // As long as there are double number of frequency of a character there is 
        // possiblity of the palindrome match.
        for (int r = len-1; r >= 0; r--) {
            if (s[l] == s[r]) {
                l++;
            }
        }
        if (l == len) return s;
        
        // 0 to l there are each unique character has frequencey count of atleast 2
        // except middle one which is anways counted twice while running above loop
        
        string remStr = s.substr(l);
        cout<<"remStr = "<<remStr<<endl;
        reverse(remStr.begin(),remStr.end());
        cout<<"remStr = "<<remStr<<endl;
        return remStr + shortestPalindrome(s.substr(0,l)) + s.substr(l);
    }
};