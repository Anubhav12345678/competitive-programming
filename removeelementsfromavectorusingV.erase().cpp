int Solution::removeElement(vector<int> &A, int B) {
    int i=0,j=0;
    int n = A.size();
    int ind=0;
    for(i=0;i<n;i++)
    if(A[i]!=B)
    A[j++]=A[i];
    vector<int>::iterator it1,it2;
    it1 = A.begin()+j;
    it2 = A.end();
    A.erase(it1,it2);
    return A.size();
    // return A.size();
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
