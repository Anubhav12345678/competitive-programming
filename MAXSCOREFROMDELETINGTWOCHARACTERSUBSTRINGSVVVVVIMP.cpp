#include "solution.hpp"
using namespace std;

/*
You are given a string s containing "1"s and "0"s and integers zeroone and onezero. In one operation you can remove any substring "01" and receive zeroone points. Or you can remove any substring "10" and receive onezero points.

Return the maximum number of points you can receive, given that you can make any number of operations.


*/
class Solution {
    public:
    int solve(string s, int zeroone, int onezero) {
        // Write your code here
         // Write your code here
        int n = s.size(), cnt0 = 0,  cnt1 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0')cnt0++;
            else cnt1++;
        }
        int low = min(cnt0, cnt1);
        int curr = 0, ans = 0, num = 0;
        if(zeroone > onezero){
            for(int i = n-1; i >= 0; i--){
                if(s[i] == '1'){
                    curr++;
                }else{
                    if(curr > 0){
                        curr--;
                        ans += zeroone;
                        num++;
                    }
                }
            }
            ans += onezero*(low - num);
        }else{
            for(int i = 0; i < n; i++){
                if(s[i] == '1'){
                    curr++;
                }else{
                    if(curr > 0){
                        curr--;
                        ans += onezero;
                        num++;
                    }
                }
            }
            ans += zeroone*(low - num);
        }
        return ans;
    }
};
