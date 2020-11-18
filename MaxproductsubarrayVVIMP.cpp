//LEETCODE
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i,j,k,l,n=nums.size();
        int ans=1;
        if(n==1) return nums[0];
        if(n==2&&nums[0]==-1&&nums[1]==-1) return 1;
       ans  = nums[0];
        int imax,imin;
        // imax max subarr prod ending at i
        //imin min subarr prod ending at i
        imax = ans;
        imin=ans;
        for(i=1;i<n;i++){
            if(nums[i]<0)
                swap(imax,imin);
            
            imax = max(nums[i],imax*nums[i]);
            imin = min(nums[i],imin*nums[i]);
            ans = max(ans,imax);
        }
        return ans;
    }
};






// niche gfg fail ho rha [-1,-1,0] pr






// C++ program to find Maximum Product Subarray 
#include <bits/stdc++.h> 
using namespace std; 

/* Returns the product of max product subarray. 
Assumes that the given array always has a subarray 
with product more than 1 */
int maxSubarrayProduct(int arr[], int n) 
{ 
	// max positive product ending at the current position 
	int max_ending_here = 1; 

	// min negative product ending at the current position 
	int min_ending_here = 1; 

	// Initialize overall max product 
	int max_so_far = 1; 
	int flag = 0; 
	/* Traverse through the array. Following values are 
	maintained after the i'th iteration: 
	max_ending_here is always 1 or some positive product 
					ending with arr[i] 
	min_ending_here is always 1 or some negative product 
					ending with arr[i] */
	for (int i = 0; i < n; i++) { 
		/* If this element is positive, update max_ending_here. 
		Update min_ending_here only if min_ending_here is 
		negative */
		if (arr[i] > 0) { 
			max_ending_here = max_ending_here * arr[i]; 
			min_ending_here = min(min_ending_here * arr[i], 1); 
			flag = 1; 
		} 

		/* If this element is 0, then the maximum product 
		cannot end here, make both max_ending_here and 
		min_ending_here 0 
		Assumption: Output is alway greater than or equal 
					to 1. */
		else if (arr[i] == 0) { 
			max_ending_here = 1; 
			min_ending_here = 1; 
		} 

		
	/* If element is negative. This is tricky 
		max_ending_here can either be 1 or positive. 
		min_ending_here can either be 1 or negative. 
		next max_ending_here will always be prev. 
		min_ending_here * arr[i] ,next min_ending_here 
		will be 1 if prev max_ending_here is 1, otherwise 
		next min_ending_here will be prev max_ending_here * 
		arr[i] */

		else { 
			int temp = max_ending_here; 
			max_ending_here = max(min_ending_here * arr[i], 1); 
			min_ending_here = temp * arr[i]; 
		} 

		// update max_so_far, if needed 	
		if (max_so_far < max_ending_here) 
			max_so_far = max_ending_here; 
	} 
	if (flag == 0 && max_so_far == 1) 
		return 0; 
	return max_so_far; 
} 

// Driver code 
int main() 
{ 
	int arr[] = {-4,-3}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << "Maximum Sub array product is "
		<< maxSubarrayProduct(arr, n); 
	return 0; 
} 

// This is code is contributed by rathbhupendra 
// me
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
int solve(vector<int> &v)
{
	int n = v.size();
	if(n==1)
	return v[0];
	int i,j,k,l,maxhere=1,maxsofar=1,f=0,minhere=1;
	for(i=0;i<n;i++)
	{
		if(v[i]>0)
		{
			maxhere = max(maxhere*v[i],1);
			minhere = min(minhere*v[i],1);
			f=1;
		}
		else if(v[i]==0)
		{
			maxhere=1;
			minhere=1;
		}
		else
		{
			int t = maxhere;
			maxhere = max(minhere*v[i],1);
			minhere = t*v[i];
		}
		if(maxsofar<maxhere)
		maxsofar = maxhere;
	}
	if(f==0&&maxsofar==1)
	return 0;
	return maxsofar;
}
int main() {
	int n,i,j,k,l;
	cin>>n;
	vector<int> v(n);
	for(i=0;i<n;i++) cin>>v[i];
	cout<<solve(v);
	// your code goes here
	return 0;
}