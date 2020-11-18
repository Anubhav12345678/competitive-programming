// C++ implementation of the above approach 
#include <bits/stdc++.h> 
using namespace std; 

bool areBookingsPossible(int arrival[], 
						int departure[], int n, int k) 
{ 
	vector<pair<int, int> > ans; 

	// create a common vector both arrivals 
	// and departures. 
	for (int i = 0; i < n; i++) { 
		ans.push_back(make_pair(arrival[i], 1)); 
		ans.push_back(make_pair(departure[i], 0)); 
	} 

	// sort the vector 
	sort(ans.begin(), ans.end()); 

	int curr_active = 0, max_active = 0; 

	for (int i = 0; i < ans.size(); i++) { 

		// if new arrival, increment current 
		// guests count and update max active 
		// guests so far 
		if (ans[i].second == 1) { 
			curr_active++; 
			max_active = max(max_active, 
							curr_active); 
		} 

		// if a guest departs, decrement 
		// current guests count. 
		else
			curr_active--; 
	} 

	// if max active guests at any instant 
	// were more than the available rooms, 
	// return false. Else return true. 
	return (k >= max_active); 
} 

int main() 
{ 
	int arrival[] = { 1, 3, 5 }; 
	int departure[] = { 2, 6, 8 }; 
	int n = sizeof(arrival) / sizeof(arrival[0]); 
	cout << (areBookingsPossible(arrival, 
								departure, n, 1) 
				? "Yes\n"
				: "No\n"); 
	return 0; 
} 
