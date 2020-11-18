// INTERVIEWBIT
int Solution::solve(vector<int> &A) {
    int i,j,k,l,n=A.size();
    int rightmax[n], leftmax[n];
    set<int> left;
    leftmax[0] = A[0];
    left.insert(A[0]);
    rightmax[n-1]=A[n-1];
    for(i=n-2;i>=0;i--)
    {
        if(rightmax[i+1]>A[i])
        rightmax[i] = rightmax[i+1];
        else
        rightmax[i] =A[i];
    }
    for(i=1;i<n;i++){
        left.insert(A[i]);
        auto it = left.find(A[i]);
        if(it!=left.begin()){
            it--;
            leftmax[i] = *it;
        }
        else
        leftmax[i] = A[i];
    }
    // for(i=0;i<n;i++){
    //     cout<<"leftmax["<<i<<"] = "<<leftmax[i]<<endl;
    //     cout<<"rightmax["<<i<<"] = "<<rightmax[i]<<endl;
    // }
    
    int ans=0;
    for(i=0;i<n;i++){
        if(A[i]!=leftmax[i]&&A[i]!=rightmax[i])
        ans = max(ans,A[i]+leftmax[i]+rightmax[i]);
    }
    return ans;
}










// C++ program to find maximum triplet sum 
#include <bits/stdc++.h> 
using namespace std; 
// in O(nlogn)
// Utility function to get the lower last min 
// value of 'n' 
int getLowValue(set<int>& lowValue, int& n) 
{ 
	auto it = lowValue.lower_bound(n); 

	// Since 'lower_bound' returns the first 
	// iterator greater than 'n', thus we 
	// have to decrement the pointer for 
	// getting the minimum value 
	--it; 

	return (*it); 
} 

// Function to calculate maximum triplet sum 
int maxTripletSum(int arr[], int n) 
{ 
	// Initialize suffix-array 
	int maxSuffArr[n + 1]; 

	// Set the last element 
	maxSuffArr[n] = 0; 

	// Calculate suffix-array containing maximum 
	// value for index i, i+1, i+2, ... n-1 in 
	// arr[i] 
	for (int i = n - 1; i >= 0; --i) 
		maxSuffArr[i] = max(maxSuffArr[i + 1], arr[i]); 

	int ans = 0; 

	// Initialize set container 
	set<int> lowValue; 

	// Insert minimum value for first comparison 
	// in the set 
	lowValue.insert(INT_MIN); 

	for (int i = 0; i < n - 1; ++i) { 
		if (maxSuffArr[i + 1] > arr[i]) { 
			ans = max(ans, getLowValue(lowValue, 
									arr[i]) 
							+ arr[i] + maxSuffArr[i + 1]); 

			// Insert arr[i] in set<> for further 
			// processing 
			lowValue.insert(arr[i]); 
		} 
	} 
	return ans; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 2, 5, 3, 1, 4, 9 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	cout << maxTripletSum(arr, n); 
	return 0; 
} 
