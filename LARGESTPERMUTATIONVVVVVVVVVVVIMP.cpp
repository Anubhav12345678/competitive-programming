vector<int> Solution::solve(vector<int> &A, int B) {
    int i,j,k,l,n=A.size();
    unordered_map<int,int> mp;
    for(i=0;i<n;i++)
    mp[A[i]]=i;
    for(i=0;i<n;i++){
        if(B>0){
            if(A[i]!=n-i){
                mp[A[i]]=mp[n-i];
                A[mp[n-i]]=A[i];
                mp[n-i]=i;
                A[i]=n-i;
               B--;
            }
        }
        else
        break;
    }
    return A;
}
/*
Given an integer array A of size N consisting of unique integers from 1 to N. You can swap any two integers atmost B times.

Return the largest lexicographical value array that can be created by executing atmost B swaps.
*/