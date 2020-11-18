// C++ Code to insert a new interval in set of sorted 
// intervals and merge overlapping intervals that are 
// formed as a result of insertion. 
#include <bits/stdc++.h> 

using namespace std; 

// Define the structure of interval 
struct Interval 
{ 
	int start; 
	int end; 
	Interval() 
		: start(0), end(0) 
	{ 
	} 
	Interval(int s, int e) 
		: start(s), end(e) 
	{ 
	} 
}; 

// A subroutine to check if intervals overlap or not. 
bool doesOverlap(Interval a, Interval b) 
{ 
	return (min(a.end, b.end) >= max(a.start, b.start)); 
} 

// Function to insert new interval and 
// merge overlapping intervals 
vector<Interval> insertNewInterval 
(vector<Interval>& Intervals, Interval newInterval) 
{ 
	vector<Interval> ans; 
	int n = Intervals.size(); 

	// If set is empty then simply insert 
	// newInterval and return. 
	if (n == 0) 
	{ 
		ans.push_back(newInterval); 
		return ans; 
	} 


	// Case 1 and Case 2 (new interval to be 
	// inserted at corners) 
	if (newInterval.end < Intervals[0].start || 
			newInterval.start > Intervals[n - 1].end) 
	{ 
		if (newInterval.end < Intervals[0].start) 
			ans.push_back(newInterval); 

		for (int i = 0; i < n; i++) 
			ans.push_back(Intervals[i]); 

		if (newInterval.start > Intervals[n - 1].end) 
			ans.push_back(newInterval); 

		return ans; 
	} 

	// Case 3 (New interval covers all existing) 
	if (newInterval.start <= Intervals[0].start && 
		newInterval.end >= Intervals[n - 1].end) 
	{ 
		ans.push_back(newInterval); 
		return ans; 
	} 

	// Case 4 and Case 5 
	// These two cases need to check whether 
	// intervals overlap or not. For this we 
	// can use a subroutine that will perform 
	// this function. 
	bool overlap = true; 
	for (int i = 0; i < n; i++) 
	{ 
		overlap = doesOverlap(Intervals[i], newInterval); 
		if (!overlap) 
		{ 
			ans.push_back(Intervals[i]); 

			// Case 4 : To check if given interval 
			// lies between two intervals. 
			if (i < n && 
				newInterval.start > Intervals[i].end && 
				newInterval.end < Intervals[i + 1].start) 
				ans.push_back(newInterval); 

			continue; 
		} 

		// Case 5 : Merge Overlapping Intervals. 
		// Starting time of new merged interval is 
		// minimum of starting time of both 
		// overlapping intervals. 
		Interval temp; 
		temp.start = min(newInterval.start, 
						Intervals[i].start); 

		// Traverse the set until intervals are 
		// overlapping 
		while (i < n && overlap) 
		{ 

			// Ending time of new merged interval 
			// is maximum of ending time both 
			// overlapping intervals. 
			temp.end = max(newInterval.end, 
						Intervals[i].end); 
			if (i == n - 1) 
				overlap = false; 
			else
				overlap = doesOverlap(Intervals[i + 1], 
										newInterval); 
			i++; 
		} 

		i--; 
		ans.push_back(temp); 
	} 

	return ans; 
} 

// Driver code 
int main() 
{ 
	vector<Interval> Intervals; 
	Interval newInterval; 

	newInterval.start = 1; 
	newInterval.end = 2; 
	Intervals.push_back(newInterval); 
	newInterval.start = 3; 
	newInterval.end = 5; 
	Intervals.push_back(newInterval); 
	newInterval.start = 6; 
	newInterval.end = 7; 
	Intervals.push_back(newInterval); 
	newInterval.start = 8; 
	newInterval.end = 10; 
	Intervals.push_back(newInterval); 
	newInterval.start = 12; 
	newInterval.end = 16; 
	Intervals.push_back(newInterval); 
	newInterval.start = 4; 
	newInterval.end = 9; 

	vector<Interval> ans = 
		insertNewInterval(Intervals, newInterval); 

	for (int i = 0; i < ans.size(); i++) 
		cout << ans[i].start << ", "
			<< ans[i].end << "\n"; 

	return 0; 
} 
