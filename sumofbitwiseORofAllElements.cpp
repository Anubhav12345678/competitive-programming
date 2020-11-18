#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
// another sol
int main(){
    ll i,j,k,l,n;
    cin>>n;
    ll ans=0LL;
    ll idx[50]={0};
    vector<ll> v(n);
    for(i=1;i<=n;i++) 
    {
        ll p;
        cin>>p;
        for(j=0;j<32;j++)
        {
            k  = (1<<j);
            if(p&k)
            {
                ans+=k*i;
                idx[j]=i;
            }
            else{
                ans+=k*idx[j];
            }
        }
    }
    cout<<ans<<endl;
}
/*
Each time we see a 1 at bit position j in tmp, (say tmp comes at ith iteration), 2^j is 
contributed i times to the sum (ans, here). This is because i subarrays are formed with this
 element. Every 0 in tmp at bit position j will contribute 2^j, idx[j] times to the sum, because
  idx[j] tells the number of subarrays that tmp will group with that has 1 set at j.
*/

// C++ program to find sum of bitwise OR 
// of all subarrays 

#include <bits/stdc++.h> 
using namespace std; 

// Function to find sum of bitwise OR 
// of all subarrays 
int givesum(int A[], int n) 
{ 
	// Find max element of the array 
	int max = *max_element(A, A + n); 

	// Find the max bit position set in 
	// the array 
	int maxBit = log2(max) + 1; 

	int totalSubarrays = n * (n + 1) / 2; 

	int s = 0; 

	// Traverse from 1st bit to last bit which 
	// can be set in any element of the array 
	for (int i = 0; i < maxBit; i++) { 
		int c1 = 0; 

		// Vector to store indexes of the array 
		// with i-th bit not set 
		vector<int> vec; 

		int sum = 0; 

		// Traverse the array 
		for (int j = 0; j < n; j++) { 

			// Check if ith bit is not set in A[j] 
			int a = A[j] >> i; 
			if (!(a & 1)) { 
				vec.push_back(j); 
			} 
		} 

		// Variable to store count of subarrays 
		// whose bitwise OR will have i-th bit 
		// not set 
		int cntSubarrNotSet = 0; 

		int cnt = 1; 

		for (int j = 1; j < vec.size(); j++) { 
			if (vec[j] - vec[j - 1] == 1) { 
				cnt++; 
			} 
			else { 
				cntSubarrNotSet += cnt * (cnt + 1) / 2; 

				cnt = 1; 
			} 
		} 

		// For last element of vec 
		cntSubarrNotSet += cnt * (cnt + 1) / 2; 

		// Variable to store count of subarrays 
		// whose bitwise OR will have i-th bit set 
		int cntSubarrIthSet = totalSubarrays - cntSubarrNotSet; 

		s += cntSubarrIthSet * pow(2, i); 
	} 

	return s; 
} 

// Driver code 
int main() 
{ 
	int A[] = { 1, 2, 3, 4, 5 }; 
	int n = sizeof(A) / sizeof(A[0]); 

	cout << givesum(A, n); 

	return 0; 
} 
