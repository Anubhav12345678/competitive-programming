int Solution::removeDuplicates(vector<int> &A) {
    int i,j=0,k,n;
    n = A.size();
    if(n==1)
    return 1;
    for(i=0;i<n-1;i++)
    {
        if(A[i]!=A[i+1])
        {
        A[j++]=A[i];
        // A[j++] = A[i+1];
        // i++;
        }
        else
        {
            while(i<n-1&&A[i]==A[i+1])
            i++;
            if(i==n-1)
            {
                A[j++]=A[i];
                break;
            }
            i--;
            // if(i==n-1)
            
        }
    }
    if(i==n-1&&A[i]!=A[i-1])
    A[j++] = A[i];
    vector<int>::iterator it1,it2;
    it1 = A.begin()+j;
    it2 = A.end();
    A.erase(it1,it2);
    return A.size();
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
