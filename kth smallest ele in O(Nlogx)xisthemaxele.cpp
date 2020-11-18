// kth smallest ele in O(Nlogx)xisthemaxele
int Solution::kthsmallest(const vector<int> &A, int B) {
    int lo = *min_element(A.begin(),A.end());
    int hi = *max_element(A.begin(),A.end());
    int i,j,k,l,r,n,mid;
    n = A.size();
    while(lo<=hi)
    {
        mid = lo+(hi-lo)/2;
        int cntless=0,cnteq=0;
        for(i=0;i<n;i++)
        {
            if(A[i]<mid)
            cntless++;
            else if(A[i]==mid)
            cnteq++;
            if(cntless>=B)
            break;
        }
        if(cntless<B&&(cntless+cnteq)>=B)
        return mid;
        if(cntless>=B)
        hi = mid-1;
        else
        lo = mid+1;
    }
    return -1;
    
}
