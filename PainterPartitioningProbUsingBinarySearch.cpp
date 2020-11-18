// CPP program for painter's partition problem 
#include <iostream> 
using namespace std; 
// here gfg sol painetr is taking 1 unit of time to paint 1 unit of len
// return the maximum element from the array 
int getMax(int arr[], int n) 
{ 
	int max = INT_MIN; 
	for (int i = 0; i < n; i++) 
		if (arr[i] > max) 
			max = arr[i]; 
	return max; 
} 

// return the sum of the elements in the array 
int getSum(int arr[], int n) 
{ 
	int total = 0; 
	for (int i = 0; i < n; i++) 
		total += arr[i]; 
	return total; 
} 

// find minimum required painters for given maxlen 
// which is the maximum length a painter can paint 
int numberOfPainters(int arr[], int n, int maxLen) 
{ 
	int total = 0, numPainters = 1; 

	for (int i = 0; i < n; i++) { 
		total += arr[i]; 

		if (total > maxLen) { 

			// for next count 
			total = arr[i]; 
			numPainters++; 
		} 
	} 

	return numPainters; 
} 

int partition(int arr[], int n, int k) 
{ 
	int lo = getMax(arr, n); 
	int hi = getSum(arr, n); 

	while (lo < hi) { 
		int mid = lo + (hi - lo) / 2; 
		int requiredPainters = numberOfPainters(arr, n, mid); 

		// find better optimum in lower half 
		// here mid is included because we 
		// may not get anything better 
		if (requiredPainters <= k) 
			hi = mid; 

		// find better optimum in upper half 
		// here mid is excluded because it gives 
		// required Painters > k, which is invalid 
		else
			lo = mid + 1; 
	} 

	// required 
	return lo; 
} 

// driver function 
int main() 
{ 
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 3; 
	cout << partition(arr, n, k) << endl; 
	return 0; 
} 


// IB sol when time taken by the painter to paint 1 unit is not one
int getsum(vector<int> &v)
{
    int n=v.size();
    int i=0,k=0;
    for(i=0;i<n;i++)
    k+=v[i];
    return k;
}
bool noofpaintersreq(vector<int> &v,int k,int maxlen)
{
    int n = v.size();
    int i,j,p=0,nop=1;
    for(i=0;i<n;i++)
     {
         p+=v[i];
         if(p>maxlen)
         {
             p = v[i];
             nop++;
         }
     }
     return (nop<=k);
}
int Solution::paint(int A, int B, vector<int> &C) {
    long long int st = (long long int)*max_element(C.begin(), C.end()); 
    long long int en = (long long int)getsum(C);
    long long int m;
    while(st<en)
    {
        m = st+(en-st)/2;
        if(noofpaintersreq(C,A,m))
        en=m;
        else
        st = m+1;
    }
    return (((st)%10000003)*((B)%10000003))%10000003;
    
    
    
}































