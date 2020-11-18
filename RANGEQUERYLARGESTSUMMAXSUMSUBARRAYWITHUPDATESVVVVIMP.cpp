// CPP program to find Largest Sum Contiguous 
// Subarray in a given range with updates 
#include <bits/stdc++.h> 
using namespace std; 

// Structure to store 
// 4 values that are to be stored 
// in the nodes 
struct node { 
	int sum, prefixsum, suffixsum, maxsum; 
}; 

// array to store the segment tree 
node tree[4 * 100]; 

// function to build the tree 
void build(int arr[], int low, int high, int index) 
{ 
	// the leaf node 
	if (low == high) { 
		tree[index].sum = arr[low]; 
		tree[index].prefixsum = arr[low]; 
		tree[index].suffixsum = arr[low]; 
		tree[index].maxsum = arr[low]; 
	} 
	else { 
		int mid = (low + high) / 2; 
		
		// left subtree 
		build(arr, low, mid, 2 * index + 1); 
		
		// right subtree 
		build(arr, mid + 1, high, 2 * index + 2); 

		// parent node's sum is the summation 
		// of left and right child 
		tree[index].sum = tree[2 * index + 1].sum + 
						tree[2 * index + 2].sum; 

		// parent node's prefix sum will be equivalent 
		// to maximum of left child's prefix sum or left 
		// child sum + right child prefix sum. 
		tree[index].prefixsum = 
					max(tree[2 * index + 1].prefixsum, 
					tree[2 * index + 1].sum + 
					tree[2 * index + 2].prefixsum); 

		// parent node's suffix sum will be equal to right 
		// child suffix sum or right child sum + suffix 
		// sum of left child 
		tree[index].suffixsum = 
					max(tree[2 * index + 2].suffixsum, 
					tree[2 * index + 2].sum + 
					tree[2 * index + 1].suffixsum); 

		// maxum will be the maximum of prefix, suffix of 
		// parent or maximum of left child or right child 
		// and summation of left child's suffix and right 
		// child's prefix. 
		tree[index].maxsum = 
					max(tree[index].prefixsum, 
					max(tree[index].suffixsum, 
					max(tree[2 * index + 1].maxsum, 
					max(tree[2 * index + 2].maxsum, 
					tree[2 * index + 1].suffixsum + 
					tree[2 * index + 2].prefixsum)))); 
	} 
} 

// function to update the tree 
void update(int arr[], int index, int low, int high, 
			int idx, int value) 
{ 
	// the node to be updated 
	if (low == high) { 
		tree[index].sum = value; 
		tree[index].prefixsum = value; 
		tree[index].suffixsum = value; 
		tree[index].maxsum = value; 
	} 
	else { 

		int mid = (low + high) / 2; 

		// if node to be updated is in left subtree 
		if (idx <= mid) 
			update(arr, 2 * index + 1, low, mid, idx, value); 
		
		// if node to be updated is in right subtree 
		else
			update(arr, 2 * index + 2, mid + 1, 
				high, idx, value); 

		// parent node's sum is the summation of left 
		// and right child 
		tree[index].sum = tree[2 * index + 1].sum + 
						tree[2 * index + 2].sum; 

		// parent node's prefix sum will be equivalent 
		// to maximum of left child's prefix sum or left 
		// child sum + right child prefix sum. 
		tree[index].prefixsum = 
					max(tree[2 * index + 1].prefixsum, 
					tree[2 * index + 1].sum + 
					tree[2 * index + 2].prefixsum); 

		// parent node's suffix sum will be equal to right 
		// child suffix sum or right child sum + suffix 
		// sum of left child 
		tree[index].suffixsum = 
					max(tree[2 * index + 2].suffixsum, 
					tree[2 * index + 2].sum + 
					tree[2 * index + 1].suffixsum); 

		// maxum will be the maximum of prefix, suffix of 
		// parent or maximum of left child or right child 
		// and summation of left child's suffix and 
		// right child's prefix. 
		tree[index].maxsum = 
					max(tree[index].prefixsum, 
					max(tree[index].suffixsum, 
					max(tree[2 * index + 1].maxsum, 
					max(tree[2 * index + 2].maxsum, 
					tree[2 * index + 1].suffixsum + 
					tree[2 * index + 2].prefixsum)))); 
	} 
} 

// fucntion to return answer to every type-1 query 
node query(int arr[], int index, int low, 
		int high, int l, int r) 
{ 
	// initially all the values are INT_MIN 
	node result; 
	result.sum = result.prefixsum = 
				result.suffixsum = 
				result.maxsum = INT_MIN; 

	// range does not lies in this subtree 
	if (r < low || high < l) 
		return result; 

	// complete overlap of range 
	if (l <= low && high <= r) 
		return tree[index]; 

	int mid = (low + high) / 2; 

	// right subtree 
	if (l > mid) 
		return query(arr, 2 * index + 2, 
					mid + 1, high, l, r); 
		
	// left subtree	 
	if (r <= mid) 
		return query(arr, 2 * index + 1, 
					low, mid, l, r); 

	node left = query(arr, 2 * index + 1, 
					low, mid, l, r); 
	node right = query(arr, 2 * index + 2, 
						mid + 1, high, l, r); 

	// finding the maximum and returning it 
	result.sum = left.sum + right.sum; 
	result.prefixsum = max(left.prefixsum, left.sum + 
						right.prefixsum); 
							
	result.suffixsum = max(right.suffixsum, 
					right.sum + left.suffixsum); 
	result.maxsum = max(result.prefixsum, 
					max(result.suffixsum, 
					max(left.maxsum, 
					max(right.maxsum, 
					left.suffixsum + right.prefixsum)))); 
					
	return result; 
} 

// Driver Code 
int main() 
{ 
	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 }; 
	int n = sizeof(a) / sizeof(a[0]); 

	// build the tree 
	build(a, 0, n - 1, 0); 

	// 1st query type-1 
	int l = 5, r = 8; 
	cout << query(a, 0, 0, n - 1, l - 1, r - 1).maxsum; 
	cout << endl; 

	// 2nd type-2 query 
	int index = 1; 
	int value = 10; 
	a[index - 1] = value; 
	update(a, 0, 0, n - 1, index - 1, value); 

	// 3rd type-1 query 
	l = 1, r = 3; 
	cout << query(a, 0, 0, n - 1, l - 1, r - 1).maxsum; 

	return 0; 
} 
