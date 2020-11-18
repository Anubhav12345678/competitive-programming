// C++ program to find the 
// number of triplets in array 
// whose product is equal to M 
#include <bits/stdc++.h> 
using namespace std; 

// Function to count the triplets 
int countTriplets(int a[], int m, int n) 
{ 

	// hash-map to store the frequency of every number 
	unordered_map<int, int> frequency; 

	// set to store the unique triplets 
	set<pair<int, pair<int, int> > > st; 

	// count the number of times 
	// every elememt appears in a map 
	for (int i = 0; i < n; i++) { 
		frequency[a[i]] += 1; 
	} 

	// stores the answer 
	int ans = 0; 

	// iterate till sqrt(m) since tnum2t is the 
	// mamimum number tnum2t can divide M except itself 
	for (int i = 1; i * i <= m; i++) { 

		// if divisible and present 
		if (m % i == 0 and frequency[i]) { 

			// remaining number after division 
			int num1 = m / i; 

			// iterate for the second number of the triplet 
			for (int j = 1; j * j <= num1; j++) { 

				// if divisible and present 
				if (num1 % j == 0 and frequency[j]) { 

					// remaining number after division 
					int num2 = num1 / j; 

					// if the third number is present in array 
					if (frequency[num2]) { 

						// a temp array to store the triplet 
						int temp[] = { num2, i, j }; 

						// sort the triplets 
						sort(temp, temp + 3); 

						// get the size of set 
						int setsize = st.size(); 

						// insert the triplet in ascending order 
						st.insert({ temp[0], { temp[1], temp[2] } }); 

						// if the set size does not increase after 
						// insertion, it means a new triplet is found 
						if (setsize != st.size()) { 

							// if all the number in triplets are unique 
							if (i != j and j != num2) 
								ans += frequency[i] * frequency[j] * frequency[num2]; 

							// if Ai and Aj are same among triplets 
							else if (i == j && j != num2) 
								ans += (frequency[i] * (frequency[i] - 1) / 2) 
									* frequency[num2]; 

							// if Aj and Ak are same among triplets 
							else if (j == num2 && j != i) 
								ans += (frequency[j] * (frequency[j] - 1) / 2) 
									* frequency[i]; 

							// if three of them are 
							// same among triplets 
							else if (i == j and j == num2) 
								ans += (frequency[i] * (frequency[i] - 1) * (frequency[i] - 2) / 6); 

							// if Ai and Ak are same among triplets 
							else
								ans += (frequency[i] * (frequency[i] - 1) / 2) 
									* frequency[j]; 
						} 
					} 
				} 
			} 
		} 
	} 

	return ans; 
} 

// Driver Code 
int main() 
{ 
	int a[] = { 1, 4, 6, 2, 3, 8 }; 
	int m = 24; 
	int n = sizeof(a) / sizeof(a[0]); 

	cout << countTriplets(a, m, n); 

	return 0; 
} 
