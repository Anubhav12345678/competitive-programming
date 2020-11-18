// C++ program to rotate an array by 
// d elements 
#include <bits/stdc++.h> 
using namespace std; 

/*Fuction to get gcd of a and b*/
int gcd(int a, int b) 
{ 
	if (b == 0) 
		return a; 

	else
		return gcd(b, a % b); 
} 

/*Function to left rotate arr[] of siz n by d*/
void leftRotate(int arr[], int d, int n) 
{ 
	int g_c_d = gcd(d, n); 
	for (int i = 0; i < g_c_d; i++) { 
		/* move i-th values of blocks */
		cout<<"arr["<<i<<"] = "<<arr[i]<<endl;
		int temp = arr[i]; 
		int j = i; 
         cout<<"temp = "<<temp;
         cout<<"j = "<<j<<endl;
		while (1) { 
			cout<<"entered while\n";
			cout<<"j = "<<j<<" d = "<<d<<endl;
			int k = j + d; 
			cout<<"k = "<<k<<endl;
			if (k >= n) 
			{
				cout<<"entered if\nk = "<<k<<endl;
				k = k - n; 
				cout<<"k = "<<k<<endl;
			}
			if (k == i) 
			{
				cout<<"i = "<<i<<endl;
				cout<<"entered 2nd if\nk = "<<k<<endl;
				break;
			}
             cout<<"arr["<<j<<"] = "<<arr[j]<<" arr["<<k<<"] = "<<arr[k]<<endl;
			arr[j] = arr[k]; 
			cout<<"arr["<<j<<"] = "<<arr[j]<<" arr["<<k<<"] = "<<arr[k]<<endl;
			cout<<"j = "<<j<<" k = "<<k<<endl;
			j = k; 
			cout<<"j = "<<j<<" k = "<<k<<endl;
		} 
		cout<<"j = "<<j<<"arr["<<"] = "<<arr[j]<<endl;
		cout<<"temp = "<<temp;
		arr[j] = temp; 
		cout<<"j = "<<j<<"arr["<<"] = "<<arr[j]<<endl;
	} 
} 

// Function to print an array 
void printArray(int arr[], int size) 
{ 
	for (int i = 0; i < size; i++) 
		cout << arr[i] << " "; 
} 

/* Driver program to test above functions */
int main() 
{ 
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	// Function calling 
	leftRotate(arr, 2, n); 
	printArray(arr, n); 

	return 0; 
} 
