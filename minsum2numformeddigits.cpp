// C++ program to find minimum sum of two numbers 
// formed from all digits in a given array. 
#include<bits/stdc++.h> 
using namespace std; 

// Returns sum of two numbers formed 
// from all digits in a[] 
int minSum(int arr[], int n) 
{ 
	// min Heap 
	priority_queue <int, vector<int>, greater<int> > pq; 

	// to store the 2 numbers formed by array elements to 
	// minimize the required sum 
	string num1, num2; 

	// Adding elements in Priority Queue 
	for(int i=0; i<n; i++) 
		pq.push(arr[i]); 

	// checking if the priority queue is non empty 
	while(!pq.empty()) 
	{ 
		// appending top of the queue to the string 
		num1+=(48 + pq.top()); 
		pq.pop(); 
		if(!pq.empty()) 
		{ 
			num2+=(48 + pq.top()); 
			pq.pop(); 
		} 
	} 

	// converting string to integer 
	int a = atoi(num1.c_str()); 
	int b = atoi(num2.c_str()); 

	// returning the sum 
	return a+b; 
} 

int main() 
{ 
	int arr[] = {6, 8, 4, 5, 2, 3}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout<<minSum(arr, n)<<endl; 
	return 0; 
} 
// Contributed By: Harshit Sidhwa 
// another method
// C++ program to find minimum sum of two numbers 
// formed from all digits in a given array. 
#include<bits/stdc++.h> 
using namespace std; 

// Returns sum of two numbers formed 
// from all digits in a[] 
int minSum(int a[], int n){ 
	
	// sort the elements 
	sort(a,a+n); 
	
	int num1 = 0; 
	int num2 = 0; 
	for(int i = 0;i<n;i++){ 
		if(i%2==0) 
			num1 = num1*10+a[i]; 
		else num2 = num2*10+a[i]; 
	} 
	return num2+num1; 
} 

// Driver code 
int main() 
{ 
	int arr[] = {5, 3, 0, 7, 4}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout<<"The required sum is "<<minSum(arr, n)<<endl; 
	return 0; 
} 
