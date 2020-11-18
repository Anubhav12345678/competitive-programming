//best
int Solution::firstMissingPositive(vector<int> &A) {
    for(int i = 0; i < A.size(); i++){
        if(A[i] > 0 && A[i] <= A.size() && (A[i] != A[A[i] - 1])){
            int temp = A[A[i] - 1];
            A[A[i] - 1] = A[i];
            A[i] = temp;
            i--;
        }
    }

    for(int i = 0; i < A.size(); i++){
        if(A[i] != i + 1){
            return i+1;
        }
    }
   

    return A.size() + 1;
    
}





/* C++ program to find the smallest positive missing number */
#include <bits/stdc++.h> 
using namespace std; 

/* Utility to swap to integers */
void swap(int *a, int *b) 
{ 
	int temp; 
	temp = *a; 
	*a = *b; 
	*b = temp; 
} 

/* Utility function that puts all 
non-positive (0 and negative) numbers on left 
side of arr[] and return count of such numbers */
int segregate (int arr[], int size) 
{ 
	int j = 0, i; 
	for(i = 0; i < size; i++) 
	{ 
		if (arr[i] <= 0) 
		{ 
			swap(&arr[i], &arr[j]); 
			j++; // increment count of non-positive integers 
		} 
	} 

	return j; 
} 

/* Find the smallest positive missing number 
in an array that contains all positive integers */
int findMissingPositive(int arr[], int size) 
{ 
	int i; 
	
	// Mark arr[i] as visited by making arr[arr[i] - 1] negative. 
	// Note that 1 is subtracted because index start 
	// from 0 and positive numbers start from 1 
	for(i = 0; i < size; i++) 
	{ 
		if(abs(arr[i]) - 1 < size && arr[ abs(arr[i]) - 1] > 0) 
		arr[ abs(arr[i]) - 1] = -arr[ abs(arr[i]) - 1]; 
	} 
	
	// Return the first index value at which is positive 
	for(i = 0; i < size; i++) 
		if (arr[i] > 0) 
			// 1 is added because indexes start from 0 
			return i+1; 
	
	return size+1; 
} 

/* Find the smallest positive missing 
number in an array that contains 
both positive and negative integers */
int findMissing(int arr[], int size) 
{ 
	// First separate positive and negative numbers 
	int shift = segregate (arr, size); 
	
	// Shift the array and call findMissingPositive for 
	// positive part 
	return findMissingPositive(arr + shift, size - shift); 
} 

// Driver code 
int main() 
{ 
	int arr[] = {0, 10, 2, -10, -20}; 	
	int arr_size = sizeof(arr)/sizeof(arr[0]); 
	int missing = findMissing(arr, arr_size); 
	cout << "The smallest positive missing number is " << missing; 
	return 0; 
} 

// This is code is contributed by rathbhupendra 
// me
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
void swap(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int segregate(vector<int> &v)
{
	int n = v.size();
	int i=0,j=0,k,l;
	for(i=0;i<n;i++)
	{
		if(v[i]<=0)
		{
			swap(&v[i],&v[j]);
			j++;
		}
	}
	return j;
}
int findmissing(vector<int> &v)
{
	int n = v.size();
	int i,j,k,l;
	for(i=0;i<n;i++)
	{
		if(abs(v[i])-1<n&&v[abs(v[i])-1]>0)
		v[abs(v[i])-1]*=-1;
	}
	for(i=0;i<n;i++)
    {
    	if(v[i]>0)
    	return i+1;
    }
    return n+1;
}
int solve(vector<int> &v)
{
	int shift  = segregate(v);
	vector<int> a(v.begin()+shift,v.end());
	return findmissing(a);
}
int main() {
	int n,i,j,k;
	cin>>n;
	vector<int> v(n);
	for(i=0;i<n;i++)
	cin>>v[i];
	// int tar;
	// cin>>tar;
	cout<<solve(v);
	// your code goes here
	return 0;
}

//BEST
int Solution::firstMissingPositive(vector<int> &A) {
    for(int i = 0; i < A.size(); i++){
        if(A[i] > 0 && A[i] <= A.size() && (A[i] != A[A[i] - 1])){
            int temp = A[A[i] - 1];
            A[A[i] - 1] = A[i];
            A[i] = temp;
            i--;
        }
    }

    for(int i = 0; i < A.size(); i++){
        if(A[i] != i + 1){
            return i+1;
        }
    }
   

    return A.size() + 1;
    
}