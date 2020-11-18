int Solution::solve(vector<int> &A) {
    int i,j,k,l,n=A.size();
    /*

Given an integer array A of size N. You need to count the number of special elements in the given array.

A element is special if removal of that element make the array balanced.

Array will be balanced if sum of even index element equal to sum of odd index element.
    */
    int ans=0,runo=0,rune=0,sume=0,sumo=0;
    vector<pair<int,int>> left(n), right(n);
    int se=0,so=0;
    for(i=0;i<n;i++){
        if(i%2==0)
        se+=A[i];
        else
        so+=A[i];
        left[i] = {se,so};
    }
    se=0;
    so=0;
    for(i=n-1;i>=0;i--){
        if(i%2==0) se+=A[i];
        else
        so+=A[i];
        right[i]  ={se,so};
    }
    
    for(i=0;i<n;i++){
        int le= left[i].first;
        int lo = left[i].second;
        int re = right[i].first;
        int ro = right[i].second;
        if(i%2==0){
            le-=A[i];
            re-=A[i];
        }
        else{
            ro-=A[i];
            lo-=A[i];
        }
        if((lo+re)==(le+ro)) ans++;
    }
    return ans;
    
}
