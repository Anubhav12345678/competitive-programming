// C++ implementation of the approach 
#include<bits/stdc++.h> 
using namespace std; 

	// Function to concatenate array 
	void arrayConcatenate(int *arr, int *b, 
								int k,int len) 
	{ 
		// Array b will be formed by concatenation 
		// array a exactly k times 
		int j = 0; 
		while (k > 0) 
		{ 

			for (int i = 0; i < len; i++) 
			{ 
				b[j++] = arr[i]; 
			} 
			k--; 
		} 
	} 

	// Function to return the maximum 
	// subarray sum of arr[] 
	long maxSubArrSum(int *a,int len) 
	{ 
		int size = len; 
		int max_so_far = INT_MIN; 
		long max_ending_here = 0; 

		for (int i = 0; i < size; i++) 
		{ 
			max_ending_here = max_ending_here + a[i]; 
			if (max_so_far < max_ending_here) 
				max_so_far = max_ending_here; 
			if (max_ending_here < 0) 
				max_ending_here = 0; 
		} 
		return max_so_far; 
	} 

	// Function to return the maximum sub-array 
	// sum of the modified array 
	long maxSubKSum(int *arr, int k,int len) 
	{ 
		int arrSum = 0; 
		long maxSubArrSum1 = 0; 

		int b[(2 * len)]={0}; 

		// Concatenating the array 2 times 
		arrayConcatenate(arr, b, 2,len); 

		// Finding the sum of the array 
		for (int i = 0; i < len; i++) 
			arrSum += arr[i]; 

		// If sum is less than zero 
		if (arrSum < 0) 
			maxSubArrSum1 = maxSubArrSum(b,2*len); 

		// If sum is greater than zero 
		else
			maxSubArrSum1 = maxSubArrSum(b,2*len) + 
						(k - 2) * arrSum; 

		return maxSubArrSum1; 
	} 

	// Driver code 
	int main() 
	{ 
		int arr[] = { 1, -2, 1 }; 
		int arrlen=sizeof(arr)/sizeof(arr[0]); 
		int k = 5; 
		cout << maxSubKSum(arr, k,arrlen) << endl; 
		return 0; 
	} 
	
// This code is contributed by mits 
//LEETCODE
class Solution {
public:
    void concatenate(vector<int> &a,vector<int> &b,int k)
    {
        b.clear();
        int i,j,l;
        while(k>0)
        {
            for(i=0;i<a.size();i++)
                b.push_back(a[i]);
            k--;
        }
    }
    int maxarrsum(vector<int> &a)
    {
        int n = a.size();
        int i,j,k,l;
        int maxhere=0,maxsofar=0;
        for(i=0;i<n;i++)
        {
            maxhere+=a[i];
            if(maxhere<0)
                maxhere=0;
            if(maxhere>maxsofar)
                maxsofar=maxhere;
        }
        return maxsofar;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int mod = 1000000007;
        int n = arr.size();
        vector<int> b(2*n);
        int i,j,l;
        long long int s=0;
        long long int ans=0,maxsum=0;
        concatenate(arr,b,2);
        for(i=0;i<n;i++)
            s+=arr[i];
        if(s<0)
            ans = maxarrsum(b)%mod;
        else
            ans = ((maxarrsum(b))%mod+((long long int)(k-2)*s)%mod)%mod;
        return (int)(ans%mod);
        
            
    }
};