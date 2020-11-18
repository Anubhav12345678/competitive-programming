void Solution::nextPermutation(vector<int> &A) {
     int i,j,k,n;
        n = A.size();
    // cout<<"entered function\n";
    // for(i=0;i<A.size();i++)
    // cout<<A[i]<<" ";
    // int i,j,k,n;
    for(i=0;i<n-1;i++)
    {
        if(A[i]<A[i+1])
        break;
    }
    
    if(i==n-1)
    {
        sort(A.begin(),A.end());
        return;
    }
    else
    {
        for(i=n-2;i>=0;i--)
        if(A[i]<A[i+1])
        break;
        int y = i;
        // cout<<"y = "<<y<<endl;
        int x = i+1;
        // cout<<"x = "<<x+1<<endl;
        for(j=i+2;j<n;j++)
        if(A[j]>A[y]&&A[j]<A[x])
        x = j;
        int t = A[x];
        A[x] = A[y];
        A[y] = t;
        sort(A.begin()+i+1,A.end());
 //   for(i=0;i<n;i++)
 //   {
 //       // cout<<"in function\n";
    // cout<<A[i]<<" ";
 //   }
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
