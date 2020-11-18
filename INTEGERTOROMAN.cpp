#include <iostream>
using namespace std;
#include<string.h>
string solve(int A)
{
	 string res = "";
    if(A==0)
    return res;
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int t = A,i=12,j,d;
    // string res = "";
    
    while(t>0)
    {
       d = t/num[i];
       t = t%num[i];
       while(d--)
       res+=sym[i];
       i--;
    }
    return res;
}
int main() {
	int n;
	cin>>n;
	cout<<solve(n);
	// your code goes here
	return 0;
}