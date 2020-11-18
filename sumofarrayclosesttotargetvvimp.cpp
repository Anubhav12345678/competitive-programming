
/*

Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than
 value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.

In case of a tie, return the minimum such integer.

Notice that the answer is not neccesarilly a number from arr.

 

Example 1:

Input: arr = [4,9,3], target = 10
Output: 3
Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.

*/

class Solution {
public:
    int findBestValue(vector<int>& x, int t) {
        int n=x.size();
        if(n==0)
            return 0;
        sort(x.begin(),x.end());
        int i,j,k,l,bi,at=0,sum=0;
        long long int best = INT_MAX;
        // cout<<"all ok\n";
        for(i=0;i<=t+10;i++)
        {
            // cout<<"i="<<i<<endl;
            // cout<<"all ok\n";
            while(at<n&&x[at]<=i)
            {
                // cout<<"inwhile\n";
                // cout<<"all ok\n";
                sum+=x[at];
                at++;
                // cout<<"inwhile\n";
            }
            // cout<<"all ok\n";
            long long int tmp=sum+(n-at)*i;
            tmp=abs(tmp-t);
            if(tmp<best)
            {
                // cout<<"best= "<<best<<" tmp = "<<tmp<<endl;
                // cout<<"inif\n";
                best=tmp;
                bi=i;
                // cout<<"bi="<<bi<<endl;
            }
        }
        return bi;
    }
};