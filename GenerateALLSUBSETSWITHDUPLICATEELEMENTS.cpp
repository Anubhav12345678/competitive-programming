  vector<vector<int> > subsetsWithDup(vector<int> &S) {
            vector<vector<int> > result; 
            vector<int> current;
            sort(S.begin(), S.end());
            generateSubsets(S, 0, current, result);
            sort(result.begin(), result.end());
            return result;
        }

        void generateSubsets(vector<int> &S, int index, vector<int> &current, vector<vector<int> > &result) {
            if (index >= S.size()) {
                result.push_back(current);
                return;
            }
            // Find the number of occurence of the element at current index. 
            int curIndex = index + 1;
            while (curIndex < S.size() && S[curIndex] == S[index]) {
                curIndex++;
            }

            // There are curIndex - index number of repeating entries. 
            // Now we loop over the number of entries to include in our subset. 
            for (int i = 0; i <= (curIndex - index); i++) {
                for (int j = 0; j < i; j++) current.push_back(S[index]);
                generateSubsets(S, curIndex, current, result);
                for (int j = 0; j < i; j++) current.pop_back();
            }
        }