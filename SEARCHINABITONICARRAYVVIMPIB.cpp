int Solution::solve(vector<int> &A, int B) {
    int i,j,k,l,n=A.size();
    i=0;
    for(i=0;i<n-1;i++){
        if(A[i]>A[i+1]) break;
    }
    
    if(A[i]==B) return i;
    int st=i;
    int en=n-1;
    while(st<=en){
        int m= (st+en)/2;
        if(A[m]==B) return m;
        if(A[m]<B) en=m-1;
        else
        st=m+1;
    }
    
    st=0;
    en=i;
    while(st<=en){
        int m= (st+en)/2;
        if(A[m]==B) return m;
        if(A[m]<B) st=m+1;
        else
        en=m-1;
    }
    
    return -1;
}

