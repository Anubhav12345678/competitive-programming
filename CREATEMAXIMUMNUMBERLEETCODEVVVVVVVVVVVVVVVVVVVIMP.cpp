class Solution {
public:
    /*
Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length
 k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return 
 an array of the k digits.

Note: You should try to optimize your time and space complexity.

Example 1:

Input:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
Output:
[9, 8, 6, 5, 3]
    */
    vector<int> findmax(vector<int> &v,int k){
        int i,j,l,m,n=v.size();
        vector<int> res(k);
        // cout<<"findnmax\n";
        int len=0;
        for(i=0;i<n;i++){
            while(len>0&&(len+n-i)>k&&v[i]>res[len-1])
                len--;
            if(len<k)
                res[len++]= v[i];
        }
        
        return res;
    }
    
    vector<int> merge(vector<int> &a,vector<int> &b){
        int i=0,j=0,k=0,l=0,n1=a.size();
        int n2 = b.size();
        // cout<<"merge\n";
        vector<int> res(n1+n2);
        while(k<(n1+n2)){
            if(greater(a,i,b,j))
                res[k++] = a[i++];
            else
                res[k++] = b[j++];
        }
        
        return res;
    }
    bool greater(vector<int> &v1,int pos1,vector<int> &v2, int pos2){
        int i,j,k,l,n1=v1.size(),n2=v2.size();
        // cout<<"greaet\n";
        i=0;
        j=0;
        while(pos1<n1&&pos2<n2&& v1[pos1]==v2[pos2])
        {
            pos1++;
            pos2++;
        }
        
        if(pos2==n2) return true;
        if(pos1<n1&&v1[pos1]>v2[pos2])
            return true;
        return false;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int i,j,l,n1=nums1.size();
        int n2 = nums2.size();
        vector<int> res(k,-1);
        for(i=max(0,k-n2);i<=min(k,n1);i++){
            // cout<<"ok\n";
            vector<int> v1 = findmax(nums1,i);
            vector<int> v2 = findmax(nums2,k-i);
            
            vector<int> cur = merge(v1,v2);
            if(greater(cur,0,res,0))
                res=cur;
        }
        return res;
    }
};