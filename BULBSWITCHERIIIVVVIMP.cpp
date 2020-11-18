/*

There is a room with n bulbs, numbered from 1 to n, arranged in a row from left to right. Initially, all the bulbs are turned off.

At moment k (for k from 0 to n - 1), we turn on the light[k] bulb. A bulb change color to blue only if it is on and all the previous bulbs (to the left) are turned on too.

Return the number of moments in which all turned on bulbs are blue.





*/





class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int i,j,k=0,l,n=light.size();
        // int sum[n+1]={0};
        int on=0,cnt=0;
        for(i=0;i<n;i++)
        {
            on++;
            k = max(k,light[i]);
            if(k==on)
                cnt++;
        }
        return cnt;
        
        
    }
};