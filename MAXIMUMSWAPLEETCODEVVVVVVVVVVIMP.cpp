class Solution {
public:
    int maximumSwap(int num) {
        int i,j,k,l;
        string s = to_string(num);
        cout<<s<<endl;
        int n =s.size();
        vector<int> last(10,-1);
        for(i=0;i<n;i++)
            last[s[i]-'0'] = i;
        // cout<<"ok";
        for(i=0;i<n;i++)
        {
            for(int d = 9;d>(s[i]-'0');d--){
                if(last[d]>i){
                    // cout<<"ok";
                    char t = s[i];
                    s[i] = s[last[d]];
                    s[last[d]] = t;
                    return stoi(s);
                }
            }
        }
        return num;
    }
};
/*
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. 
Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.


*/