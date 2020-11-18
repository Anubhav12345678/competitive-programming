#include <iostream>
using namespace std;
#include<vector>
int solve(vector<int>&coins) {
    int n = coins.size();
    int moves = 0;
    int farZero = -1;
    int extraCoins = 0;
    for (int i = 0; i < n; ++i) {
        if (coins[i] == 0) {
            if (extraCoins > 0) {
                extraCoins--;
                moves++;
                continue;
            }
            farZero = (farZero == -1) ? i : farZero;
        } else {
            if (farZero == -1) {
                if (extraCoins > 0) moves++;
                extraCoins += (coins[i] - 1);
                continue;
            }
            // assert(extraCoins == 0);
            int totZeros = i - farZero;
            moves += totZeros;
            if (coins[i] <= totZeros) {
                farZero = farZero + coins[i];
            } else {
                farZero = -1;
                extraCoins += (coins[i] - totZeros - 1);
            }
        }
    }
    return moves;
}
int main() {
	int n;
	cin>>n;
	vector<int> c(n);
	for(int i=0;i<n;i++)
	cin>>c[i];
	cout<<solve(c);
	// your code goes here
	return 0;
}


//meeee
#include <iostream>
using namespace std;
#include<vector>
int solve(vector<int>&coins) {
    int i,j,k,l,n=coins.size();
    int farzero=-1;
    int moves=0;
    int extracoins=0;
    for(i=0;i<n;i++){
    	if(coins[i]==0)
    	{
    		if(extracoins>0)
    		{
    			extracoins--;
    			moves++;
    			continue;
    		}
    		farzero=(farzero==-1)?i:farzero;
    	}
    	else
    	{
    		if(farzero==-1)
    		{
    			if(extracoins>0) moves++;
    			extracoins+=(coins[i]-1);
    			continue;
    		}
    		int totzero = i-farzero;
    		moves+=totzero;
    		if(coins[i]<=totzero)
    		farzero+=coins[i];
    		else
    		{
    			farzero=-1;
    			extracoins+=(coins[i]-totzero-1);
    		}
    	}
    }
    return moves;
}
int main() {
	int n;
	cin>>n;
	vector<int> c(n);
	for(int i=0;i<n;i++)
	cin>>c[i];
	cout<<solve(c);
	// your code goes here
	return 0;
}