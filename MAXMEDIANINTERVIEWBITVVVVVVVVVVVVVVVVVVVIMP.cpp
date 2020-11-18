string Solution::solve(vector<int> &A, string B) {
    long long n = A.size();
     auto isOk = [&](long long median, long long b, long long operation) {
         for(int i=n/2; i < n; ++i) {
             if(median - A[i] > 0)
                operation += (median - A[i]);
            if(operation > b)
                return false;
         }
         return (operation <= b);
     };
     
     long long b = stoll(B);
     long long lo = 0;
     long long hi = A.back() + b+1;
     while(lo<hi) {
         long long mid = (lo+hi+1)/2;
         if(isOk(mid, b, 0LL))
            lo = mid;
         else
            hi = mid-1;
        
     }
     return to_string(lo);
}
/*
You are given a sorted array A of N integers, where N is odd. You can make the following operation with it:

Choose one of the elements of the array (for example ai) and increase it by 1 (that is, replace it with ai + 1).</li>

Return the largest possible median of the array using at most B operations.

Note: The median of the odd-sized sorted array is the middle element after the array is sorted in non-decreasing order.

*/