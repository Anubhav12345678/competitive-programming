class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
       // check number of 1s
        int oneCount = 0, n = A.size();
        for (int &i: A)
            oneCount += (i == 1);
        if (oneCount % 3 != 0)
            return vector<int> {-1, -1};
        if (oneCount == 0)
            return vector<int> {0, 2};
        
        // find last part
        int count = oneCount / 3, third = n;
        while (count > 0) {
            third--;
            if (A[third] == 1)
                count--;
        }
        
        // find first part
        int first = 0;
        while (first < n && A[first] == 0)
            first++;
        
        // check equalness of 1 and 3
        bool equal = true;
        for (int offset = 0; third + offset < n; offset++)
            if (first + offset >= third || A[first + offset] != A[third + offset])
                return vector<int> {-1, -1};
        
        // check equalness of 2 and 3
        int second = first + n - third;
        while (A[second] == 0)
            second++;
        for (int offset = 0; third + offset < n; offset++)
            if (second + offset >= third || A[second + offset] != A[third + offset])
                return vector<int> {-1, -1};

        // okay. return last position of first part and first position of third part.
        return vector<int> {first + n - third - 1, second + n - third}; 
    }
};