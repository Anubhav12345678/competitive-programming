class Solution {
public:
    bool ispalin(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i++]!=s[j--]) return 0;
        }
        return 1;
    }
    
    bool checkPalindromeFormation(string a, string b) {
       int i,j,k,l,n=a.size();
        i=0;
        j=n-1;
        while(i<j&&a[i]==b[j])
        {
            i++;
            j--;
        }
        if(ispalin(a,i,j)||ispalin(b,i,j)) return 1;
        i=0;
        j=n-1;
        while(i<j&&a[j]==b[i])
        {
            i++;
            j--;
        }
        if(ispalin(a,i,j)||ispalin(b,i,j)) return 1;
        return 0;
    }
};
/*
You are given two strings a and b of the same length. Choose an index and split both strings at the same index, splitting a into two strings: aprefix and asuffix where a = aprefix + asuffix, and splitting b into two strings: bprefix and bsuffix where b = bprefix + bsuffix. Check if aprefix + bsuffix or bprefix + asuffix forms a palindrome.

When you split a string s into sprefix and ssuffix, either ssuffix or sprefix is allowed to be empty. For example, if s = "abc", then "" + "abc", "a" + "bc", "ab" + "c" , and "abc" + "" are valid splits.

Return true if it is possible to form a palindrome string, otherwise return false.

Notice that x + y denotes the concatenation of strings x and y.

 

Example 1:

Input: a = "x", b = "y"
Output: true
Explaination: If either a or b are palindromes the answer is true since you can split in the following way:
aprefix = "", asuffix = "x"
bprefix = "", bsuffix = "y"
Then, aprefix + bsuffix = "" + "y" = "y", which is a palindrome.



*/