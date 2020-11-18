// CPP implementation of the above approach 
#include <bits/stdc++.h> 
using namespace std; 
// Minimum and maximum number of N chocolates after distribution among K students
// Driver code 
int main(){ 

	int n = 7, k = 3; 

	if(n % k == 0) 
		cout<<n/k<<" "<<n/k; 
	else
		cout<<((n-(n % k))/k)<<" "
			<<(((n-(n % k))/k) + 1); 

	return 0; 
} 

// This code is contributed by Sanjit_Prasad 
