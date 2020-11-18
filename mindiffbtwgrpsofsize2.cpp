// CPP program to find minimum difference 
// between groups of highest and lowest 
// sums. 
#include <bits/stdc++.h> 
#define ll long long int 
using namespace std; 

ll calculate(ll a[], ll n) 
{ 
	// Sorting the whole array. 
	sort(a, a + n); 

	// Generating sum groups. 
	vector<ll> s; 
	for (int i = 0, j = n - 1; i < j; i++, j--) 
	s.push_back(a[i] + a[j]); 

	ll mini = *min_element(s.begin(), s.end()); 
	ll maxi = *max_element(s.begin(), s.end()); 

	return abs(maxi - mini); 
} 

int main() 
{ 
	ll a[] = { 2, 6, 4, 3 }; 
	int n = sizeof(a) / (sizeof(a[0])); 
	cout << calculate(a, n) << endl; 
	return 0; 
} 
