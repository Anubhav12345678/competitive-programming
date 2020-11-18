// cpp code to count ways 
// to divide circle using 
// N non-intersecting chords. 
#include <bits/stdc++.h> 
using namespace std; 

int chordCnt( int A){ 

	// n = no of points required 
	int n = 2 * A; 
	
	// dp array containing the sum 
	int dpArray[n + 1]={ 0 }; 
	dpArray[0] = 1; 
	dpArray[2] = 1; 
	for (int i=4;i<=n;i+=2){ 
		for (int j=0;j<i-1;j+=2){ 
			
		dpArray[i] += 
			(dpArray[j]*dpArray[i-2-j]); 
		} 
	} 

	// returning the required number 
	return dpArray[n]; 
} 
// Driver function 
int main() 
{ 

	int N; 
	N = 2; 
cout<<chordCnt( N)<<'\n'; 
	N = 1; 
cout<<chordCnt( N)<<'\n'; 
	N = 4; 
cout<<chordCnt( N)<<'\n'; 
	return 0; 
} 

// This code is contributed by Gitanjali. 
