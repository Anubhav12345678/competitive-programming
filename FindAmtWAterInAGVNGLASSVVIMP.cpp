#include <bits/stdc++.h>
using namespace std;
#define ll long long
float solve(int i,int j,float x)
{
	if(j>i)
	return -1;
	float arr[(i*(i+1))/2];
	int ind=0;
	arr[ind] = x;
	for(int row = 1;row<=i;row++)
	{
		for(int col=1;col<=row;col++,ind++)
		{
			x = arr[ind];
			arr[ind] = (x>=1.0f)?1.0f:x;
			x = (x>=1.0f)?(x-1):0.0f;
			arr[row+col] = x/2.0;
			arr[row+col+1] = x/2.0;
		}
	}
	return arr[(i*(i-1))/2+j-1];
}
int main() {
	int i = 2, j = 2; 
    float X = 2.0; // Total amount of water 
  
    printf("Amount of water in jth glass of ith row is: %f", 
            solve(i, j, X)); 
  
    return 0; 
	// your code goes here
	return 0;
}