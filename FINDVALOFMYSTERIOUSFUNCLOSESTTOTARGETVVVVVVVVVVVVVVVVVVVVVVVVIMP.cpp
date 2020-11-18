class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int i,j,k,l,n=arr.size();
        int ans=INT_MAX;
        set<int> s1;
        for(i=0;i<n;i++){
            set<int> s2;
            s2.insert(arr[i]);
            for(auto v:s1){
                s2.insert(arr[i]&v);
            }
            for(auto v:s2){
                ans = min(ans,abs(v-target));
            }
            
            s1=s2;
        }
        return ans;
    }
};
// as we cannot produce more unique elements this sol is o(n)
//https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/discuss/746314/Simplest-O(n)-Java-Solution
/*

Winston was given the above mysterious function func. He has an integer array arr and an integer target
 and he wants to find the values l and r that make the value |func(arr, l, r) - target| minimum possible.

Return the minimum possible value of |func(arr, l, r) - target|.

Notice that func should be called with the values l and r where 0 <= l, r < arr.length.*/
/*

Input: arr = [9,12,3,7,15], target = 5
Output: 2
Explanation: Calling func with all the pairs of [l,r] =
 [[0,0],[1,1],[2,2],[3,3],[4,4],[0,1],[1,2],[2,3],[3,4],[0,2],[1,3],[2,4],[0,3],[1,4],[0,4]],
  Winston got the following results [9,12,3,7,15,8,0,3,7,0,0,3,0,0,0]. The value closest to 5 is 7 and 3, 
  thus the minimum difference is 2.
*/