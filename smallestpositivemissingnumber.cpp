// C++ Program to find the smallest  
// positive missing number 
// An O(n) Time complexity and an O(1) extra space 
#include<bits/stdc++.h>  
using namespace std;  
  
int solution(int A[],int n)  
{ 
    // Our original array 
    // Storing maximum value  
    int m = INT_MIN; 
    for(int i = 0;i < n; i++) 
    { 
        if(A[i] > m) 
        { 
            m = A[i]; 
        } 
    } 
      
    // In case all values in our array are negative  
    if (m < 1)  
    {  
        return 1;  
    }  
    if (n == 1) 
    {  
  
        //If it contains only one element  
        if (A[0] == 1)  
        {  
            return 2;  
        }  
        else 
        {  
            return 1;  
        }  
    }  
    int i = 0;  
    int l[m] = {0};  
    for (i = 0; i < n; i++) 
    {  
        if (A[i] > 0)  
        {  
            // Changing the value status  
            // at the index of our list  
            if (l[A[i] - 1] != 1)  
            {  
                l[A[i] - 1] = 1;  
            }  
        }  
    }  
      
    // Encountering first 0, i.e,  
    // the element with least value  
    for (i = 0; i < m; i++)  
    {  
        if (l[i] == 0)  
        {  
            return i + 1;  
        }  
    }  
      
    // In case all values are  
    // filled between 1 and m  
    return i + 2;  
}  
  
// Driver code 
int main() 
{  
  
    int A[] = {0, 10, 2, -10, -20};  
    cout << solution(A,5);  
}  
  