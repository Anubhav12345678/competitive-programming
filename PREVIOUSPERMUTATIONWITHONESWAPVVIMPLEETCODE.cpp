class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size();
        int i,j,k,l,x,y;
        for(i=n-2;i>=0;i--)
            if(A[i]>A[i+1])
                break;
        if(i==-1)
            return A;
        x=i+1;
        for(j=i+2;j<n;j++)
            if(A[j]<A[i]&&A[j]>A[x])
                x=j;
        cout<<i<<" "<<x<<endl;
        int t = A[i];
        A[i]  =A[x];
        A[x]=t;
        // sort();
        return A;
        
    }
};