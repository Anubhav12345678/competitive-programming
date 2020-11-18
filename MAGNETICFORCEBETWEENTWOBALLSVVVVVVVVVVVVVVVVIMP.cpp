class Solution {
public:
    int dis(vector<int> &v,int m){
        int ans=1;
        int st=0,i,j,k,l,n=v.size();
        // cout<<" m = "<<m<<endl;
        for(i=0;i<n;i++){
            if((v[i]-v[st])>=m)
            {
                // cout<<"ok\n";
                ans++;
                st=i;
                // cout<<"st = "<<st<<endl;
            }
        }
        return ans;
    }
    int solve(vector<int> &v,int m){
        int i,j,k,l,n=v.size();
        sort(v.begin(),v.end());
        int r;
        l = 0;
        r = v[n-1]-v[0];
        // cout<<"l = "<<l<<" r = "<<r<<endl;
        int ans=0;
        while(l<=r){
            int mid = l+(r-l)/2;
            // cout<<"mid = "<<mid<<" l = "<<l<<" r = "<<r<<endl;
           int  x = dis(v,mid);
            // cout<<"x = "<<x<<endl;
            if(x<m){
                r=mid-1;
            }
            else{
                ans=mid;
                l=mid+1;
            }
            // cout<<"ans = "<<ans<<endl;
        }
        return ans;
    }
    int maxDistance(vector<int>& position, int m) {
        return solve(position,m);
    }
};
/*

In universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put 
in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls 
and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.

 

Example 1:


Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
E


*/