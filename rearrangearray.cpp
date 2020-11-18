/*better*/


void Solution::arrange(vector<int> &A) {
    int i,j,k,l,n=A.size();
    for(i=0;i<n;i++)
    {
        A[i]+=(A[A[i]]%n)*n;
    }
    for(i=0;i<n;i++)
    A[i]=A[i]/n;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}









// CPP program for rearrange an 
// array such that arr[i] = i. 
#include <iostream.h> 

using namespace std; 

// Function to rearrange an array 
// such that arr[i] = i. 
int fix(int A[], int len) 
{ 
	for (int i = 0; i < len; i++) 
	{ 
		if (A[i] != -1 && A[i] != i) 
		{ 
			int x = A[i]; 

			// check if desired place 
			// is not vacate 
			while (A[x] != -1 && A[x] != x) 
			{ 
				// store the value from 
				// desired place 
				int y = A[x]; 

				// place the x to its correct 
				// position 
				A[x] = x; 

				// now y will become x, now 
				// search the place for x 
				x = y; 
			} 

			// place the x to its correct 
			// position 
			A[x] = x; 

			// check if while loop hasn't 
			// set the correct value at A[i] 
			if (A[i] != i) 
			{ 

				// if not then put -1 at 
				// the vacated place 
				A[i] = -1; 
			} 
		} 
	} 
} 

// Driver function. 
int main() 
{ 
	int A[] = { -1, -1, 6, 1, 9, 
				3, 2, -1, 4, -1 }; 

	int len = sizeof(A) / sizeof(A[0]); 
	fix(A, len); 

	for (int i = 0; i < len; i++) 
		cout << A[i] << " "; 
} 

// This code is contributed by Smitha Dinesh Semwal 
