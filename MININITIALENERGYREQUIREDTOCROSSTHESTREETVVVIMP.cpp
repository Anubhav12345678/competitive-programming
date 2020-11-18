// C++ program to find minimum initial energy to 
// reach end 
#include<bits/stdc++.h> 
using namespace std; 

// Function to calculate minimum initial energy 
// arr[] stores energy at each checkpoints on street 
int minInitialEnergy(int arr[], int n) 
{ 
	// initMinEnergy is variable to store minimum initial 
	// energy required. 
	int initMinEnergy = 0; 

	// currEnergy is variable to store current value of 
	// energy at i'th checkpoint on street 
	int currEnergy = 0; 

	// flag to check if we have successfully crossed the 
	// street without any energy loss <= o at any checkpoint 
	bool flag = 0; 

	// Traverse each check point lineraly 
	for (int i=0; i<n; i++) 
	{ 
		currEnergy += arr[i]; 

		// If current energy, becomes negative or 0, increment 
		// initial minimum energy by the negative value plus 1. 
		// to keep current energy positive (at least 1). Also 
		// update current energy and flag. 
		if (currEnergy <= 0) 
		{ 
			initMinEnergy += abs(currEnergy) +1; 
			currEnergy = 1; 
			flag = 1; 
		} 
	} 

	// If energy never became negative or 0, then 
	// return 1. Else return computed initMinEnergy 
	return (flag == 0)? 1 : initMinEnergy; 
} 

// Driver Program to test the case 
int main() 
{ 
	int arr[] = {4, -10, 4, 4, 4}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << minInitialEnergy(arr, n); 
	return 0; 
} 
