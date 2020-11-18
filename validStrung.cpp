int Solution::isValid(string A) {
    stack<char> st;
            map<char, char> matchingBracket; 
            matchingBracket['{'] = '}';
            matchingBracket['['] = ']';
            matchingBracket['('] = ')';
            for (int i = 0; i < A.length(); i++) {
                if (A[i] == '(' || A[i] == '{' || A[i] == '[') {
                    st.push(A[i]);
                } else if (st.empty() || matchingBracket[st.top()] != A[i]) {
                    return false;
                } else {
                    st.pop();
                }
            }
            return st.empty();
}
