
/*
Return the lexicographically smallest subsequence of text that contains all the distinct characters of text exactly once.

 

Example 1:

Input: "cdadabcc"
Output: "adbc"
Example 2:

Input: "abcd"
Output: "abcd"
Example 3:

Input: "ecbacba"
Output: "eacb"
Example 4:

Input: "leetcode"
Output: "letcod"






*/




class Solution {
public:
    string smallestSubsequence(string text) {
        stack<char> st;
	vector<int> last(256, 0), seen(256, 0);
	for(int i = 0; i < text.size(); i++)
		last[text[i]] = i;
	for(int i = 0; i < text.size(); i++){
		if(seen[text[i]])
			continue;

		while(st.size() and st.top() > text[i] and last[st.top()] > i)
			seen[st.top()] = 0, st.pop(); 

		st.push(text[i]), seen[text[i]] = 1;
	}
	string res = "";
	while(st.size())
		res += st.top(), st.pop();
	reverse(res.begin(), res.end());
	return res;
    }
};