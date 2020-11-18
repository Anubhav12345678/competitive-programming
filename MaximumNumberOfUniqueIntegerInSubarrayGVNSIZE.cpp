// An efficient Approach to count distinct elements in 
// every window of size k 
#include<bits/stdc++.h> 
using namespace std; 
//Function to find maximum unique element in 
//a subarray of size k 
int max_U_element(int a[],int N,int M) 
{ 
	//map to store the unique elements and their size 
	map<int,int> hash; 
	//Number of unique elements in an window 
	int dist_count=0;	 
	int res=0;	 //Maximum unique element in a window 
	//store all elements till size k i.e. 
	//storing first window 
	for(int i=0;i<M;i++) 
	{ 
		//found an unique element 
		if(hash.find(a[i])==hash.end()) 
		{ 
			hash.insert(make_pair(a[i],1)); 
			dist_count++; 
		} 
		//an Duplicate element inserting 
		else
		{ 
			//Update the size of that element 
			hash[a[i]]++; 
		} 
	} 
	res=dist_count; 
	//Traverse till the end of array 
	for(int i=M;i<N;i++) 
	{ 
		//Remove fist element from map 
		if(hash[a[i-M]]==1) 
		{ 
			//when element present only one time 
			// in window so delete this 
			hash.erase(a[i-M]); 
			dist_count--; 
		} 
		else
		{ 
			//when multiple time element has occurred 
			// in window so decrease size by one 
			hash[a[i-M]]--; 
		} 
		//Add new element to map 
		//If element is unique to map 
		//increment count 
		if(hash.find(a[i])==hash.end()) 
		{ 
			hash.insert(make_pair(a[i],1)); 
			dist_count++; 
		} 
		//Duplicate element found 
		//update the size of that element 
		else
		{ 
			hash[a[i]]++; 
		} 
		//Update the res 
		res=max(res,dist_count); 
	} 
	return res; 
} 
//Driver code 
int main() 
{ 
	int arr[] = {1, 2, 1, 3, 4, 2, 3}; 
	int M=4,N=sizeof(arr)/sizeof(arr[0]); 
	cout<<max_U_element(arr,N,M)<<endl; 

} 
