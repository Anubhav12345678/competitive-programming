   void generateSubsets(vector<int> &S, int index, vector<int> &current, vector<vector<int> > &result) {
            if (index >= S.size()) {
                result.push_back(current);
                return;
            }
            // Ignore the current index.
            generateSubsets(S, index + 1, current, result);

            // Include the current index. 
            current.push_back(S[index]);
            generateSubsets(S, index + 1, current, result);
            current.pop_back();
        }
vector<vector<int> > Solution::subsets(vector<int> &A) {
 vector<vector<int> > result; 
            vector<int> current;
            sort(A.begin(), A.end());
            generateSubsets(A, 0, current, result);
            sort(result.begin(), result.end());
            return result;
}
