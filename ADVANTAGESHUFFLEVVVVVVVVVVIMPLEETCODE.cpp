class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int i,j,k,l,n=A.size();
        multiset<int> s(A.begin(),A.end());
        for(i=0;i<n;i++){
            auto p = (*(s.rbegin())<=B[i])?s.begin():s.upper_bound(B[i]);
            A[i]= *p;
            s.erase(p);
        }
        //erasing by iterator takes constant time
        
        return A;
        
    }
};
/*
Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].

Return any permutation of A that maximizes its advantage with respect to B.

 

Example 1:

Input: A = [2,7,11,15], B = [1,10,4,11]
Output: [2,11,7,15]

*/