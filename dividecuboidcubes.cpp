// CPP program to find optimal way to break 
// cuboid into cubes. 
#include <bits/stdc++.h> 
using namespace std; 

// Print the maximum side and no of cube. 
void maximizecube(int l, int b, int h) 
{ 
	// GCD to find side. 
	int side = __gcd(l, __gcd(b, h)); 

	// dividing to find number of cubes. 
	int num = l / side; 
	num = (num * b / side); 
	num = (num * h / side); 

	cout << side << " " << num << endl; 
} 

// Driver code 
int main() 
{ 
	int l = 2, b = 4, h = 6; 

	maximizecube(l, b, h); 
	return 0; 
} 
