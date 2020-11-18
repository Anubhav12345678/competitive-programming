#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
#include<set>
/*
Tzuyu gave Nayeon a strip of N cells (numbered 1 through N) for her birthday. This strip is described by a sequence A1,A2,…,AN, where 
for each valid i, the i-th cell is blocked if Ai=1 or free if Ai=0. Tzuyu and Nayeon are going to use it to play a game with the 
following rules:

The players alternate turns; Nayeon plays first.
Initially, both players are outside of the strip. However, note that afterwards during the game, their positions are always different.
In each turn, the current player should choose a free cell and move there. Afterwards, this cell becomes blocked and the players cannot 
ove to it again.
If it is the current player's first turn, she may move to any free cell.
Otherwise, she may only move to one of the left and right adjacent cells, i.e. from a cell c, the current player may only move to the 
cell c−1 or c+1 (if it is free).
If a player is unable to move to a free cell during her turn, this player loses the game.
Nayeon and Tzuyu are very smart, so they both play optimally. Since it is Nayeon's birthday, she wants to know if she can beat Tzuyu. 
Find out who wins.



*/
int main() {
	ll i,j,k,l,n,t;
	cin>>t;
	while(t--){
		cin>>n;
		ll a[n];
		for(i=0;i<n;i++) cin>>a[i];
		// ll v=0;
		vector<ll> v;
		for(i=0;i<n;i++){
			if(a[i]==0){
				j=i;
				while(j<n&&a[j]==0) j++;
				v.pb(j-i);
				i=j-1;
			}
		}
		sort(v.begin(),v.end(),greater<>());
		// for(i=0;i<v.size();i++) cout<<v[i]<</
		
		// bool f=1;
        if(v.size()==0){
        	cout<<"No\n";
        	// continue;
        }
        else if(v.size()==1){
        	if(v[0]%2==0)
        	cout<<"No\n";
        	else
        	cout<<"Yes\n";
        	// continue;
        }
		else{
			if(v[0]%2==0)
			cout<<"No\n";
			else{
		  ll z = (v[0]+1)/2;
		  if(z<=v[1])
		  cout<<"No\n";
		  else
		  cout<<"Yes\n";
			}
			
		}
	}
	// your code goes here
	return 0;
}