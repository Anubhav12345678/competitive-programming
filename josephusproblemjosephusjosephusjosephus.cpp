int find_pos(vector<int> &v,int n,int k,int i)
{
    if(v.size()==1)
    return v[0];
    int p = (i+(k-1))%v.size();
    v.erase(v.begin()+p);
    return find_pos(v,n,k,p);
}
int josephus(int n, int k)
{
    vector<int> v;
    for(int i=0;i<n;i++)
    v.push_back(i+1);
    return find_pos(v,n,k,0);
   //Your code here
}
// SPECIALLY FOR k=2
// C/C++ program to find solution of Josephus 
// problem when size of step is 2. 
#include <stdio.h> 

// Returns position of survivor among a circle 
// of n persons and every second person being 
// killed 
int josephus(int n) 
{ 
    // Find value of 2 ^ (1 + floor(Log n)) 
    // which is a power of 2 whose value 
    // is just above n. 
    int p = 1; 
    while (p <= n) 
        p *= 2; 

    // Return 2n - 2^(1+floor(Logn)) + 1 
    return (2 * n) - p + 1; 
} 

// Driver Program to test above function 
int main() 
{ 
    int n = 16; 
    printf("The chosen place is %d", josephus(n)); 
    return 0; 
} 
