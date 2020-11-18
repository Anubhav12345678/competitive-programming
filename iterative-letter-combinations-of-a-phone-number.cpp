//BESTTTTTTTTTTTTTTTTTTTTTTTTTTTT

    

        void generateHelper(string &current, int index, string &digits, vector<string> &ans,vector<string> &tab) {
            if (index == digits.length()) {
                ans.push_back(current);
                return;
            }
            int digit = digits[index] - '0';
            for (int i = 0; i < tab[digit].length(); i++) {
                current.push_back(tab[digit][i]);
                generateHelper(current, index + 1, digits, ans,tab);
                current.pop_back();
            }
            return;
        }
vector<string> Solution::letterCombinations(string A) {
      vector<string> tab(10);

        // Solution() {
            tab[0] = "0";
            tab[1] = "1";
            tab[2] = "abc";
            tab[3] = "def";
            tab[4] = "ghi";
            tab[5] = "jkl";
            tab[6] = "mno";
            tab[7] = "pqrs";
            tab[8] = "tuv";
            tab[9] = "wxyz";
            vector<string> ans;
            string current = "";
            generateHelper(current, 0, A, ans,tab);
            return ans;
}




















// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return a vector that contains 
// all the generated letter combinations 
vector<string> letterCombinationsUtil(const int number[], 
									int n, 
									const string table[]) 
{ 
	// To store the generated letter combinations 
	vector<string> list; 

	queue<string> q; 
	q.push(""); 

	while (!q.empty()) { 
		string s = q.front(); 
		q.pop(); 

		// If complete word is generated 
		// push it in the list 
		if (s.length() == n) 
			list.push_back(s); 
		else

			// Try all possible letters for current digit 
			// in number[] 
			for (auto letter : table[number[s.length()]]) 
				q.push(s + letter); 
	} 

	// Return the generated list 
	return list; 
} 

// Function that creates the mapping and 
// calls letterCombinationsUtil 
void letterCombinations(const int number[], int n) 
{ 

	// table[i] stores all characters that 
	// corresponds to ith digit in phone 
	string table[10] 
		= { "", "", "abc", "def", "ghi", "jkl", 
			"mno", "pqrs", "tuv", "wxyz" }; 

	vector<string> list 
		= letterCombinationsUtil(number, n, table); 

	// Print the contents of the vector 
	for (auto word : list) 
		cout << word << " "; 

	return; 
} 

// Driver program 
int main() 
{ 
	int number[] = { 2, 3 }; 
	int n = sizeof(number) / sizeof(number[0]); 

	letterCombinations(number, n); 

	return 0; 
} 
