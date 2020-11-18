// Merging two sorted arrays with O(1) 
// extra space 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find next gap. 
int nextGap(int gap) 
{ 
    if (gap <= 1) 
        return 0; 
    return (gap / 2) + (gap % 2); 
} 

void merge(int *arr1, int *arr2, int n, int m) 
{ 
    int i, j, gap = n + m; 
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) 
    { 
        // comparing elements in the first array. 
        for (i = 0; i + gap < n; i++) 
            if (arr1[i] > arr1[i + gap]) 
                swap(arr1[i], arr1[i + gap]); 

        //comparing elements in both arrays. 
        for (j = gap > n ? gap-n : 0 ; i < n&&j < m; i++, j++) 
            if (arr1[i] > arr2[j]) 
                swap(arr1[i], arr2[j]); 

        if (j < m) 
        { 
            //comparing elements in the second array. 
            for (j = 0; j + gap < m; j++) 
                if (arr2[j] > arr2[j + gap]) 
                    swap(arr2[j], arr2[j + gap]); 
        } 
    } 
} 

// Driver code 
int main() 
{ 
    int a1[] = { 10, 27, 38, 43 ,82 }; 
    int a2[] = { 3,9 }; 
    int n = sizeof(a1) / sizeof(int); 
    int m = sizeof(a2) / sizeof(int); 

    merge(a1, a2, n, m); 

    printf("First Array: "); 
    for (int i = 0; i < n; i++) 
        printf("%d ", a1[i]); 

    printf("\nSecond Array: "); 
    for (int i = 0; i < m; i++) 
        printf("%d ", a2[i]); 
    printf("\n"); 
    return 0; 
} 









// makes two arrays as first then last 
// for eg
// v1 = {1,5,7,9,11}
// v2 = {2,3,8,10,20}
//after this fun
// v1 = {1,2,3,5,7}
// v2 = {8,9,10,11,20}
// merges both arrays in O(1) space
void solve(std::vector<int> &v1,std::vector<int> v2)
{
	int i,j,k,l,m=v1.size(),n=v2.size();
    for(i=n-1;i>=0;i--)
    {
    	int last = v1[m-1];
    		for(j=m-2;j>=0&&v1[j]>v2[i];j++)
    			v1[j+1]=v1[j];
    		if(j!=m-2||last>v2[i])// if some greater number is found in v1
    		{
               v1[j+1]= v2[i];
               v2[i] = last;
    		}
    }
}