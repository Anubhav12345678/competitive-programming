// C++ program to find the minimum possible 
// difference between maximum and minimum 
// elements when we have to add/subtract 
// every number by k 
#include <bits/stdc++.h> 
using namespace std; 

// Modifies the array by subtracting/adding 
// k to every element such that the difference 
// between maximum and minimum is minimized 
int getMinDiff(int arr[], int n, int k) 
{ 
	if (n == 1) 
	return 0; 

	// Sort all elements 
	sort(arr, arr+n); 

	// Initialize result 
	int ans = arr[n-1] - arr[0]; 

	// Handle corner elements 
	int small = arr[0] + k; 
	int big = arr[n-1] - k; 
	if (small > big) 
	swap(small, big); 

	// Traverse middle elements 
	for (int i = 1; i < n-1; i ++) 
	{ 
		int subtract = arr[i] - k; 
		int add = arr[i] + k; 

		// If both subtraction and addition 
		// do not change diff 
		if (subtract >= small || add <= big) 
			continue; 

		// Either subtraction causes a smaller 
		// number or addition causes a greater 
		// number. Update small or big using 
		// greedy approach (If big - subtract 
		// causes smaller diff, update small 
		// Else update big) 
		if (big - subtract <= add - small) 
			small = subtract; 
		else
			big = add; 
	} 

	return min(ans, big - small); 
} 

// Driver function to test the above function 
int main() 
{ 
	int arr[] = {4, 6}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	int k = 10; 
	cout << "\nMaximum difference is "
		<< getMinDiff(arr, n, k); 
	return 0; 
} 
//another method simple
#include <iostream>
using namespace std;
#define INT_MAX 1000000007
int main() {
	//code
	int t=0;
	cin>>t;
	while(t>0)
	{
	    int k=0;
	    cin>>k;
	    int n=0;
	    cin>>n;
	    int max=0;
	    int min=501;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        if(max<a[i])
	        max=a[i];
	        if(min>a[i])
	        min=a[i];
	    }
	    int avg=(min+max)/2;
	    if(max-min<k)
	    cout<<max-min<<endl;
	    else
	    {
	        for(int i=0;i<n;i++)
	        {
	            if(a[i]>=avg)
	            a[i]=a[i]-k;
	            else
	            a[i]=a[i]+k;
	        }
	        max=0;
	        min=INT_MAX;
	        for(int i=0;i<n;i++)
	        {
	            if(max<a[i])
	            max=a[i];
	            if(min>a[i])
	            min=a[i];
	        }
	        cout<<max-min<<endl;
	    }
	    t--;
	}
	return 0;
}