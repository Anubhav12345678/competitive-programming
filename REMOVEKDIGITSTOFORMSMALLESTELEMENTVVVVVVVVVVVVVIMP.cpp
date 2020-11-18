/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number 
is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.


*/


class Solution {
public:
    string removeKdigits(string num, int k) {
        int i,j,l,n=num.size(),m;
        if(k==n) return "0";
        i=0,j=0;
        while(j<k)
        {
            if(num[i]>num[i+1])
            {
                num.erase(num.begin()+i);
                if(i>0) i--;
                j++;
            }
            else
            i++;
        }
        // else
        //     i++;
        // cout<<num<<endl;
    for(i=0;i<num.size()-1;)
    {
        // cout<<num<<endl;
        if(num[i]=='0')
            num.erase(num.begin()+i);
        else
            break;
        cout<<num<<endl;
        // cout<<"\n\n\n";
        
    }
    return num;
    }
};