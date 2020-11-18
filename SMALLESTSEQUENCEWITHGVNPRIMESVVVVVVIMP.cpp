vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> nums;
    if(D==0)
    return nums;
    set<int> st;
    st.insert(A);
    st.insert(B);
    st.insert(C);
    while(!st.empty())
    {
        int cur = *st.begin();
        st.erase(st.begin());
        nums.push_back(cur);
        if(nums.size()==D)
        break;
        int p1 = cur*A;
        int p2 = cur*B;
        int p3 = cur*C;
        st.insert(p1);
        st.insert(p2);
        st.insert(p3);
    }
    return nums;
}
/*

Given three prime number(p1, p2, p3) and an integer k. Find the first(smallest) k integers which have only p1, p2, p3 or a combination of them as their prime factors.

Example:

Input :
Prime numbers : [2,3,5]
k : 5

If primes are given as p1=2, p2=3 and p3=5 and k is given as 5, then the sequence of first 5 integers will be:

Output:
{2,3,4,5,6}






*/