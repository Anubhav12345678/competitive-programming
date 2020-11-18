class Solution {
public:
    /*
You are the operator of a Centennial Wheel that has four gondolas, and each gondola has room for up to four people.
 You have the ability to rotate the gondolas counterclockwise, which costs you runningCost dollars.

You are given an array customers of length n where customers[i] is the number of new customers arriving just before
 the ith rotation (0-indexed). This means you must rotate the wheel i times before customers[i] arrive. Each customer
  pays boardingCost dollars when they board on the gondola closest to the ground and will exit once that gondola reaches 
  the ground again.

You can stop the wheel at any time, including before serving all customers. If you decide to stop serving customers, 
all subsequent rotations are free in order to get all the customers down safely. Note that if there are currently more
 than four customers waiting at the wheel, only four will board the gondola, and the rest will wait for the next rotation.

Return the minimum number of rotations you need to perform to maximize your profit. If there is no scenario where the 
profit is positive, return -1.


    */
    int minOperationsMaxProfit(vector<int>& customers, int bc, int rc) {
        int i,j,k,l,n=customers.size();
        int ans=0,cnt=0,w=0,cur=0,res=-1;
        for(i=0;i<n;i++){
            int x = customers[i];
            if(x>=4)
            {
                cur+=4;
                w+=(x-4);
            }
            else{
                int y = w;
                if((x+w)>=4){
                    w-=(4-x);
                    cur+=4;
                }
                else
                {
                    cur+=(x+w);
                    w=0;
                }
                // cur+=x;
            }
            cnt++;
            int tmp = cur*bc-cnt*rc;
            if(tmp>ans){
                res=cnt;
                ans=tmp;
            }
        }
        // cout<<"ans = "<<ans<<" res = "<<res<<endl;
        while(w>0){
            if(w>=4)
            {
                cur+=4;
                w-=4;
                cnt++;
                int tmp = cur*bc-cnt*rc;
            if(tmp>ans){
                res=cnt;
                ans=tmp;
            }  
            }
            else
            {
                cur+=w;
                cnt++;
                int tmp = cur*bc-cnt*rc;
            if(tmp>ans){
                res=cnt;
                ans=tmp;
            }
                w=0;
                break;
            }
        }
        if(ans>=0) return res;
        else
            return -1;
        // return ans;
    }
};