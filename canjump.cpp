int Solution::canJump(vector<int> &A) {
    int n=A.size();
if(n==1) return 1;
if(A[0]==0) return 0;

int possibleEnd=0;
for(int i=0;i<n;i++){
    
    if(possibleEnd<i){
        return 0; //it means that as the possible end is less than this index, it won't be able to reach here and hence cannotreach the end of the array
    }
    
    possibleEnd=max(possibleEnd, i+ A[i]); // if possibleEnd is already more than the jump this index has to offer, we don't jump from this and keep the possibleEnd as it is. 
    
    if(possibleEnd>=n) return 1; // end can be reached.
    
}
}


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        if(n==1)
            return 1;
        if(n==0||nums[0]==0)
            return false;
        vector<int>  A(nums.begin(),nums.end());
        int maxi=A[0];
        for(i=0;i<n;i++)
        {
            if(maxi<=i&&A[i]==0)
                return false;
            maxi = max(maxi,A[i]+i);
            if(maxi>=n-1)
                return 1;
        }
        return 0;
        
    }
};










class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        if(n==0||n==1)
            return 1;
        if(nums[0]==0)
            return 0;
        int jump[n];
        memset(jump,INT_MAX,sizeof(jump));
        jump[0]=0;
        for(i=1;i<n;i++)
        {
            jump[i]=INT_MAX;
            for(j=0;j<i;j++)
            {
                if(i<=nums[j]+j&&jump[j]!=INT_MAX)
                {
                    jump[i] = min(jump[i],jump[j]+1);
                    break;
                }
            }
        }
        return jump[n-1]!=INT_MAX;
    }
};