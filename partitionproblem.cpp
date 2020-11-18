#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool issubsetsum(ll a[],ll n,ll sum)
{
	if(sum==0)
	return true;
	if(n==0&&sum!=0)
	return false;
	if(a[n-1]>sum)
	return issubsetsum(a,n-1,sum);
	return issubsetsum(a,n-1,sum)||issubsetsum(a,n-1,sum-a[n-1]);
}
bool isposspar(ll a[],ll n)
{
	if(n==0||n==1)
	return false;
	ll s=0,i;
	for(i=0;i<n;i++)
	s+=a[i];
	if(s%2!=0)
	return false;
	else
	return issubsetsum(a,n,s/2);
}
int main() {
	
	ll arr[] = {3, 1, 5, 9, 12};  
    ll n = sizeof(arr)/sizeof(arr[0]);  
    if (isposspar(arr, n) == true)  
        cout << "Can be divided into two subsets "
                "of equal sum";  
    else
        cout << "Can not be divided into two subsets"
                " of equal sum";  
    return 0;
}
//the above sol has exponential complexity
// the sol below is for not much larger sums 
// it is a dp so, of complexity O(sum*n)
// A Dynamic Programming based C program to partition problem 
#include <stdio.h> 

// Returns true if arr[] can be partitioned in two subsets of 
// equal sum, otherwise false 
bool findPartiion (int arr[], int n) 
{ 
	int sum = 0; 
	int i, j; 
	
	// Caculcate sun of all elements 
	for (i = 0; i < n; i++) 
	sum += arr[i]; 
	
	if (sum%2 != 0) 
	return false; 
	
	bool part[sum/2+1][n+1]; 
	
	// initialize top row as true 
	for (i = 0; i <= n; i++) 
	part[0][i] = true; 
		
	// initialize leftmost column, except part[0][0], as 0 
	for (i = 1; i <= sum/2; i++) 
	part[i][0] = false;	 
	
	// Fill the partition table in botton up manner 
	for (i = 1; i <= sum/2; i++) 
	{ 
	for (j = 1; j <= n; j++) 
	{ 
		part[i][j] = part[i][j-1]; 
		if (i >= arr[j-1]) 
		part[i][j] = part[i][j] || part[i - arr[j-1]][j-1]; 
	}		 
	}	 
	
	/* // uncomment this part to print table 
	for (i = 0; i <= sum/2; i++) 
	{ 
	for (j = 0; j <= n; j++) 
		printf ("%4d", part[i][j]); 
	printf("\n"); 
	} */
	
	return part[sum/2][n]; 
}	 

// Driver program to test above funtion 
int main() 
{ 
int arr[] = {3, 1, 1, 2, 2, 1}; 
int n = sizeof(arr)/sizeof(arr[0]); 
if (findPartiion(arr, n) == true) 
	printf("Can be divided into two subsets of equal sum"); 
else
	printf("Can not be divided into two subsets of equal sum"); 
getchar(); 
return 0; 
} 
