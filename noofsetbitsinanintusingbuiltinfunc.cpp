// C++ program to demonstrate __builtin_popcount() 
#include <iostream> 
using namespace std; 
// to count no of set bits in an int
int main() 
{ 
cout << __builtin_popcount (4) << endl; 
cout << __builtin_popcount (15); 

return 0; 
} 
//below is sum of nit diff of all pairs of elements in an array
#include<iostream>
using namespace std;
int main()
 {
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    int bitDiff = 0;
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            int x = a[i]^a[j];
	            bitDiff += __builtin_popcount(x);// To count number of set bits
	            
	        }
	    }
	    cout<<bitDiff<<endl;
	}
	return 0;
}
