class Solution {
public:
   
    bool canThreePartsEqualSum(vector<int>& A) {
       long long sum = accumulate(A.begin(), A.end(), 0LL);

        if (sum % 3 != 0)
            return false;

        long long running = 0;
        int times = 0;

        for (int i = 0; i < (int) A.size(); i++) {
            running += A[i];

            if (running == sum / 3) {
                running = 0;
                times++;
            }
        }

        return times == 3;
    }
};