
/*
Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.

 
Follow up:
Could you solve it using only O(1) extra space?

 
Example 1:

Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".





*/





class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i,j,k,l,sz=0;
        for(i=0;i<n;i++)
        {
            int cnt=1;
            char cur = chars[i];
            while(i<n-1&&chars[i+1]==cur)
            {
                i++;
                cnt++;
            }
            chars[sz++]=cur;
            if(cnt>1)
            {
                string p = to_string(cnt);
                for(j=0;j<p.size();j++)
                    chars[sz++]=p[j];
            }
        }
        return sz;
    }
};