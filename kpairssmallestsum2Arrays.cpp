// C++ program to Prints first k pairs with 
// least sum from two arrays. 

#include<bits/stdc++.h> 

using namespace std; 
// Function to find k pairs with least sum such 
// that one elemennt of a pair is from arr1[] and 
// other element is from arr2[] 
vector<int> kSmallestPair(vector<int> A, vector<int> B, int K) 
{ 
	sort(A.begin(), A.end()); 
	sort(B.begin(), B.end()); 

	int N = A.size(); 
// Min heap which contains tuple of the format 
	// (sum, (i, j)) i and j are the indices 
	// of the elements from array A 
	// and array B which make up the sum. 

	priority_queue< pair<int, pair<int, int> >,vector< pair<int, pair<int, int> > >,greater< pair<int, pair<int, int> > > > pq; 

// my_set is used to store the indices of 
	// the pair(i, j) we use my_set to make sure 
	// the indices doe not repeat inside min heap. 
	
	set<pair<int, int> > my_set; 

// initialize the heap with the minimum sum 
	// combination i.e. (A[0] + B[0]) 
	// and also push indices (0,0) along 
	// with sum. 

	pq.push(make_pair(A[0] + B[0], make_pair(0,0))); 

	my_set.insert(make_pair(0,0)); 

	// iterate upto K 

	for (int count=0; count<K; count++){	 

		// tuple format (sum, i, j). 
		pair<int, pair<int, int> > temp = pq.top(); 
		pq.pop(); 

		int i = temp.second.first; 
		int j = temp.second.second; 
		
		cout<<"("<<A[i]<<", "<<B[j]<<")"<<endl;		 //Extracting pair with least sum such that one element 
											//is from arr1 and another is from arr2 

		int sum = A[i+1] + B[j]; 
		// insert (A[i + 1] + B[j], (i + 1, j)) 
		// into min heap. 
		pair<int, int> temp1 = make_pair(i+1, j); 
		
		// insert only if the pair (i + 1, j) is 
		// not already present inside the map i.e. 
		// no repeating pair should be present inside 
		// the heap. 

		if (my_set.find(temp1) == my_set.end()) { 
			pq.push(make_pair(sum, temp1)); 
			my_set.insert(temp1); 
		} 

		// insert (A[i] + B[j + 1], (i, j + 1)) 
		// into min heap. 

		sum = A[i] + B[j+1]; 
		temp1 = make_pair(i, j+1); 

		// insert only if the pair (i, j + 1) 
		// is not present inside the heap. 

		if (my_set.find(temp1) == my_set.end()) { 
			pq.push(make_pair(sum, temp1)); 
			my_set.insert(temp1); 
		} 
	} 
} 

// Driver Code. 
int main() 
{ 
	vector<int> A = {1,3,11}; 
	vector<int> B = {2,4,8}; 
	int K = 4; 
	kSmallestPair(A, B, K); 
	return 0; 
} 

// This code is contributed by Dhairya. 
