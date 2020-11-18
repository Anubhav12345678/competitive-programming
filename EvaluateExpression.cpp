int Solution::evalRPN(vector<string> &A) {
        stack<int> st;
            for(int i = 0; i < A.size(); ++i) {
                if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/") {
                    int v1=st.top();
                    st.pop();
                    int v2=st.top();
                    st.pop();
                    switch(A[i][0]) {
                        case '+':
                            st.push(v2 + v1);
                            break;
                        case '-':
                            st.push(v2 - v1);
                            break;
                        case '*':
                            st.push(v2 * v1);
                            break;
                        case '/':
                            st.push(v2 / v1);
                            break;
                    }
                } else {
                    st.push(stoi(A[i]));
                }
            }
            return st.top();
}
