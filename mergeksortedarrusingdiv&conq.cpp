//INTERVIEWBITVVVVVVVVVVVVVVVVVVVVVVIMP
struct comp{
    bool operator()(vector<int> const &d1 , vector<int> const &d2){
        return d1[0] > d2[0];
    }  
};
vector<int> Solution::solve(vector<vector<int> > &A) {
    vector<int> head;
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    for(int i = 0; i < A.size(); i++){
        pq.push(A[i]);
    }
    while(!pq.empty()){
        vector<int> temp = pq.top();
        pq.pop();
        int op = temp[0];
        if(temp.size()>1){
            temp.erase(temp.begin());
            pq.push(temp);
        }
        head.push_back(op);
    }
    return head;
}
// C++ program to merge K sorted arrays 

#include <iostream> 
#define n 4 

using namespace std; 

// Function to perform merge operation 
void merge(int l, int r, int* output) 
{ 
	// to store the starting point of left 
	// and right array 
	int l_in = l * n, r_in = ((l + r) / 2 + 1) * n; 

	// to store the size of left and 
	// right array 
	int l_c = ((l + r) / 2 - l + 1) * n; 
	int r_c = (r - (l + r) / 2) * n; 

	// array to temporarily store left 
	// and right array 
	int l_arr[l_c], r_arr[r_c]; 

	// storing data in left array 
	for (int i = 0; i < l_c; i++) 
		l_arr[i] = output[l_in + i]; 

	// storing data in right array 
	for (int i = 0; i < r_c; i++) 
		r_arr[i] = output[r_in + i]; 

	// to store the current index of 
	// temporary left and right array 
	int l_curr = 0, r_curr = 0; 

	// to store the current index 
	// for output array 
	int in = l_in; 

	// two pointer merge for two sorted arrays 
	while (l_curr + r_curr < l_c + r_c) { 
		if (r_curr == r_c || (l_curr != l_c && 
			l_arr[l_curr] < r_arr[r_curr])) 
			output[in] = l_arr[l_curr], l_curr++, in++; 
		else
			output[in] = r_arr[r_curr], r_curr++, in++; 
	} 
} 

// Code to drive merge-sort and 
// create recursion tree 
void divide(int l, int r, int* output, 
			int arr[][n]) 
{ 
	if (l == r) { 

		/* base step to initialize the output 
		array before performing merge 
		operation */
		for (int i = 0; i < n; i++) 
			output[l * n + i] = arr[l][i]; 

		return; 
	} 

	// to sort left half 
	divide(l, (l + r) / 2, output, arr); 

	// to sort right half 
	divide((l + r) / 2 + 1, r, output, arr); 

	// merge the left and right half 
	merge(l, r, output); 
} 

// Driver Cunction 
int main() 
{ 
	// input 2D-array 
	int arr[][n] = { { 5, 7, 15, 18 }, 
					{ 1, 8, 9, 17 }, 
					{ 1, 4, 7, 7 } }; 

	// Number of arrays 
	int k = sizeof(arr) / sizeof(arr[0]); 

	// Output array 
	int* output = new int[n * k]; 

	divide(0, k - 1, output, arr); 

	// Print merged array 
	for (int i = 0; i < n * k; i++) 
		cout << output[i] << " "; 

	return 0; 
} 
