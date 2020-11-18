#include <iostream>
using namespace std;
#define ll long long
// search for an ele in a sorted and rotated arr
ll findpivot(ll a[],ll low,ll high)
{
	//pivot=-1 denotes the arr is not rotated at all
	if(high<low)
	return -1;
	if(high==low)
	return low;
	ll mid = low+(high-low)/2;
	if(mid<high&&a[mid]>a[mid+1])
	return mid;
	if(mid>low&&a[mid]<a[mid-1])
	return mid-1;
	if(a[low]>=a[mid])
	return findpivot(a,low,mid-1);
	else
	return findpivot(a,mid+1,high);
}
ll binsearch(ll a[],ll low,ll high,ll key)
{
	if(high<low)
	return -1;
	ll mid = (high+low)/2;
	if(a[mid]==key)
	return mid;
	if(a[mid]>key)
	return binsearch(a,low,mid-1,key);
	if(a[mid]<key)
	return binsearch(a,mid+1,high,key);
	
}

ll findinsortedandrotatedarr(ll a[],ll n,ll key)
{
	ll piv = findpivot(a,0,n-1);// as pivot for the whole arr is same
	if(piv==-1)//pivot=-1 denotes the arr is not rotated at all
	return binsearch(a,0,n-1,key);
	if(a[piv]==key)
	return piv;
	if(a[0]<=key)// if a[0]>keythen search for it in left subarr else in right subarr
    return binsearch(a,0,piv-1,key);
    else
    return binsearch(a,piv+1,n-1,key);
	
}
int main() {
	// Let us search 3 in below array 
  ll arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}; 
  ll n = sizeof(arr1)/sizeof(arr1[0]); 
  ll key = 3; 
    
  // Function calling 
  cout << "Index of the element is : " <<  
           findinsortedandrotatedarr(arr1, n, key); 
             
  return 0;
	// your code goes here
	return 0;
}
// IB soln by passing vector
/*
If you are getting TLE in O(log N) then this might be one of the reasons you are getting it. I tried and got the results.
 When you are passing the vector to find pivot or do a binary search. Pass it as it is, as in don’t assign the const 
 vector &A to another vector which can be modified. This increases the complexity of your algorithm.

*/
int findpivot(const vector<int> &v,int l,int h)
{
    if(h<l)
    return -1;
    if(h==l)
    return l;
    int m = l+(h-l)/2;
    if(m<h&&v[m]>v[m+1])
    return m;
    if(m>l&&v[m-1]>v[m])
    return m-1;
    if(v[l]>=v[m])
    return findpivot(v,l,m-1);
    else
    return findpivot(v,m+1,h);
}
int binsearch(const vector<int> &v,int l,int h,int k)
{
    if(h<l)
    return -1;
    int m = l+(h-l)/2;
    if(v[m]==k)
    return m;
    if(v[m]>k)
    return binsearch(v,l,m-1,k);
    else
    return binsearch(v,m+1,h,k);
}
int searchinar(const vector<int> &v,int k)
{
    int n = v.size();
    int piv = findpivot(v,0,n-1);
    if(piv==-1)
    return binsearch(v,0,n-1,k);
    if(v[piv]==k)
    return piv;
    if(v[0]<=k)
    return binsearch(v,0,piv-1,k);
    else
    return binsearch(v,piv+1,n-1,k);
    
}
int Solution::search(const vector<int> &A, int B) {
    return searchinar(A,B);
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
