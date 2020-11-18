int Solution::cntInc(vector<int> &A) {
    int i,j,k,l,n=A.size();
    if(n==0) return 0;
    if(n==1) return 1;
    int cnt=1, sum=0;
    for(i=0;i<n-1;i++){
        if(A[i]<A[i+1])
        cnt++;
        else{
            sum+=((cnt*(cnt+1))/2);
            cnt=1;
        }
        // cout<<" sum = "<<sum<<" cnt = "<<cnt<<endl;
    }
    sum+=((cnt*(cnt+1))/2);
    return sum;
}
/*
You are given an array of N positive integers, A1, A2 ,…, AN.

Let’s denote by A[i, j] the subarray Ai, Ai+1 ,…, Aj.

Count pairs (i, j) such that 1 ≤ i ≤ j ≤ N and subarray A[i, j] is increasing. Return the value modulo 109 + 7.

*/