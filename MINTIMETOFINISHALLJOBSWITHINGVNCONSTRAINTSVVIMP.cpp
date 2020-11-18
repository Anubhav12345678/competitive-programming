// C++ program to find minimum time to finish all jobs with 
// given number of assignees 
#include<bits/stdc++.h> 
using namespace std; 

// Utility function to get maximum element in job[0..n-1] 
int getMax(int arr[], int n) 
{ 
int result = arr[0]; 
for (int i=1; i<n; i++) 
	if (arr[i] > result) 
		result = arr[i]; 
	return result; 
} 

// Returns true if it is possible to finish jobs[] within 
// given time 'time' 
bool isPossible(int time, int K, int job[], int n) 
{ 
	// cnt is count of current assignees required for jobs 
	int cnt = 1; 

	int curr_time = 0; // time assigned to current assignee 

	for (int i = 0; i < n;) 
	{ 
		// If time assigned to current assignee exceeds max, 
		// increment count of assignees. 
		if (curr_time + job[i] > time) { 
			curr_time = 0; 
			cnt++; 
		} 
		else { // Else add time of job to current time and move 
			// to next job. 
			curr_time += job[i]; 
			i++; 
		} 
	} 

	// Returns true if count is smaller than k 
	return (cnt <= K); 
} 

// Returns minimum time required to finish given array of jobs 
// k --> number of assignees 
// T --> Time required by every assignee to finish 1 unit 
// m --> Number of jobs 
int findMinTime(int K, int T, int job[], int n) 
{ 
	// Set start and end for binary search 
	// end provides an upper limit on time 
	int end = 0, start = 0; 
	for (int i = 0; i < n; ++i) 
		end += job[i]; 

	int ans = end; // Initialize answer 

	// Find the job that takes maximum time 
	int job_max = getMax(job, n); 

	// Do binary search for minimum feasible time 
	while (start <= end) 
	{ 
		int mid = (start + end) / 2; 

		// If it is possible to finish jobs in mid time 
		if (mid >= job_max && isPossible(mid, K, job, n)) 
		{ 
			ans = min(ans, mid); // Update answer 
			end = mid - 1; 
		} 
		else
			start = mid + 1; 
	} 

	return (ans * T); 
} 

// Driver program 
int main() 
{ 
	int job[] = {10, 7, 8, 12, 6, 8}; 
	int n = sizeof(job)/sizeof(job[0]); 
	int k = 4, T = 5; 
	cout << findMinTime(k, T, job, n) << endl; 
	return 0; 
} 
