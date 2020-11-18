#include<bits/stdc++.h>
using namespace std;
#define ll long long
void TOH(ll n,char fromrod,char torod,char auxrod)
{
	if(n==1)
	{
		cout<<"Move disk 1 from"<<fromrod<<" to "<<torod<<endl;
		return;    
	}
	TOH(n-1,fromrod,auxrod,torod);
	cout<<"Move disk "<<n<<" from"<<fromrod<<" to "<<torod<<endl;
    TOH(n-1,auxrod,torod,fromrod);

}

int main()  
{  
    int n = 4; // Number of disks  
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods  
    return 0;  
} 