 void generateHelper(string &current, int numOpenBrackets, int numClosedBrackets, int n, vector<string> &ans) {
            if (numOpenBrackets == numClosedBrackets && numOpenBrackets == n) {
                ans.push_back(current);
                return;
            }
            if (numOpenBrackets > n || numClosedBrackets > n) {
                // Invalid. 
                return;
            }

            // Now we have 2 options. We can either add '(' to the string or add ')' to the string. 
            // Option 1. Add '(' 
            if (numOpenBrackets < n) {
                current.push_back('(');
                generateHelper(current, numOpenBrackets + 1, numClosedBrackets, n, ans);
                current.pop_back();
            }
            // Option 2. Add ')'
            if (numClosedBrackets < numOpenBrackets) {
                current.push_back(')');
                generateHelper(current, numOpenBrackets, numClosedBrackets + 1, n, ans);
                current.pop_back();
            }
        }

        vector<string> generateParenthesis(int n) {
            vector<string> ans;
            string current = "";
            int numOpenBrackets = 0, numClosedBrackets = 0; 
            generateHelper(current, numOpenBrackets, numClosedBrackets, n, ans);
            return ans;
        }
