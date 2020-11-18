// C++ program to find minimum length substring 
// having exactly k distinct character. 

#include <bits/stdc++.h> 
using namespace std; 

// Function to find minimum length substring 
// having exactly k distinct character. 
string findMinLenStr(string str, int k) 
{ 
	int n = str.length(); 

	// Starting index of sliding window. 
	int st = 0; 

	// Ending index of sliding window. 
	int end = 0; 

	// To store count of character. 
	int cnt[26]; 
	memset(cnt, 0, sizeof(cnt)); 

	// To store count of distinct 
	// character in current sliding 
	// window. 
	int distEle = 0; 

	// To store length of current 
	// sliding window. 
	int currlen; 

	// To store minimum length. 
	int minlen = n; 

	// To store starting index of minimum 
	// length substring. 
	int startInd = -1; 

	while (end < n) { 

		// Increment count of current character 
		// If this count is one then a new 
		// distinct character is found in 
		// sliding window. 
		cnt[str[end] - 'a']++; 
		if (cnt[str[end] - 'a'] == 1) 
			distEle++; 

		// If number of distinct characters is 
		// is greater than k, then move starting 
		// point of sliding window forward, 
		// until count is k. 
		if (distEle > k) { 
			while (st < end && distEle > k) { 
				if (cnt[str[st] - 'a'] == 1) 
					distEle--; 
				cnt[str[st] - 'a']--; 
				st++; 
			} 
		} 

		// Remove characters from the beginning of 
		// sliding window having count more than 1 
		// to minimize length. 
		if (distEle == k) { 
			while (st < end && cnt[str[st] - 'a'] > 1) { 
				cnt[str[st] - 'a']--; 
				st++; 
			} 

			// Comapre length with minimum length 
			// and update if required. 
			currlen = end - st + 1; 
			if (currlen < minlen) { 
				minlen = currlen; 
				startInd = st; 
			} 
		} 

		end++; 
	} 

	// Return minimum length substring. 
	return str.substr(startInd, minlen); 
} 

// Driver code 
int main() 
{ 
	string str = "efecfefd"; 

	int k = 4; 

	cout << findMinLenStr(str, k); 

	return 0; 
} 
