// C# code to find whether an array is 
// subset of another array 
using System; 
using System.Collections.Generic; 

class GFG 
{ 
/* Return true if arr2[] is a 
subset of arr1[] */
public static bool isSubset(int[] arr1, 
							int[] arr2, 
							int m, int n) 
{ 
	HashSet<int> hset = new HashSet<int>(); 

	// hset stores all the values of arr1 
	for (int i = 0; i < m; i++) 
	{ 
		if (!hset.Contains(arr1[i])) 
		{ 
			hset.Add(arr1[i]); 
		} 
	} 

	// loop to check if all elements 
	// of arr2 also lies in arr1 
	for (int i = 0; i < n; i++) 
	{ 
		if (!hset.Contains(arr2[i])) 
		{ 
			return false; 
		} 
	} 
	return true; 
} 

// Driver Code 
public static void Main(string[] args) 
{ 
	int[] arr1 = new int[] {11, 1, 13, 21, 3, 7}; 
	int[] arr2 = new int[] {11, 3, 7, 1}; 

	int m = arr1.Length; 
	int n = arr2.Length; 

	if (isSubset(arr1, arr2, m, n)) 
	{ 
		Console.WriteLine("arr2 is a subset of arr1"); 
	} 
	else
	{ 
		Console.WriteLine("arr2 is not a subset of arr1"); 
	} 
} 
} 

// This code is contributed by Shrikant13 
