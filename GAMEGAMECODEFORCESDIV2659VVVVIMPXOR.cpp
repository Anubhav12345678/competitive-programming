#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
Koa the Koala and her best friend want to play a game.

The game starts with an array a of length n consisting of non-negative integers. Koa and her best friend move in turns and 
each have initially a score equal to 0. Koa starts.

Let's describe a move in the game:

During his move, a player chooses any element of the array and removes it from this array, xor-ing it with the current score 
of the player.
More formally: if the current score of the player is x and the chosen element is y, his new score will be x⊕y. Here ⊕ denotes 
bitwise XOR operation.

Note that after a move element y is removed from a.

The game ends when the array is empty.
At the end of the game the winner is the player with the maximum score. If both players have the same score then it's a draw.

If both players play optimally find out whether Koa will win, lose or draw the game.
*/
int main() {
	ll i,j,k,l,n,t;
	cin>>t;
	while(t--){
		cin>>n;
		ll a[n];
		for(i=0;i<n;i++) cin>>a[i];
		ll cnt[32]={0};
		for(i=0;i<n;i++){
			for(j=0;j<32;j++)
			if(a[i]&(1<<j))
			cnt[j]++;
		}
		ll use=-1;
		for(i=32;i>=0;i--)
		if(cnt[i]%2){ use=i; break; }
		
		if(use==-1)
		cout<<"DRAW\n";
		else
		{
			ll x = cnt[use];
			ll p=(x+1)/2;
			if(p%2)
			cout<<"WIN\n";
			else if((n-x)%2)
			cout<<"WIN\n";
			else
			cout<<"LOSE\n";
		}
		
	}
	// your code goes here
	return 0;
}