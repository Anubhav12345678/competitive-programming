vector nextGreater(vector &A) {
if (A.empty()) return vector();

vector<int> res(A.size(), -1);
stack<int> stk;
stk.push(0);

for (int i = 1; i < (int)A.size(); i++) {
	while (!stk.empty() && A[stk.top()] < A[i]) {
		res[stk.top()] = A[i];
		stk.pop();
	}
	stk.push(i);
}

return res;
}