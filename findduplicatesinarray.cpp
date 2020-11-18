int Solution::repeatedNumber(const vector<int> &A) {
    int i=-1,j=0;
    int n = A.size();
    int slow=A[0],fast = A[A[0]];
    while(slow!=fast)
    {
        slow = A[slow];
        fast = A[A[fast]];
    }
    slow = 0;
    while(slow!=fast)
    {
        slow = A[slow];
        fast = A[fast];
    }
    return slow;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
//Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.