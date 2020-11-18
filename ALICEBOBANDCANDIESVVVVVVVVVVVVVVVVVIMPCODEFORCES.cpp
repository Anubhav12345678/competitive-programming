#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
There are n candies in a row, they are numbered from left to right from 1 to n. The size of the i-th candy is ai.

Alice and Bob play an interesting and tasty game: they eat candy. Alice will eat candy from left to right, and Bob — 
from right to left. The game ends if all the candies are eaten.

The process consists of moves. During a move, the player eats one or more sweets from her/his side (Alice eats from the 
left, Bob — from the right).

Alice makes the first move. During the first move, she will eat 1 candy (its size is a1). Then, each successive move the
 players alternate — that is, Bob makes the second move, then Alice, then again Bob and so on.

On each move, a player counts the total size of candies eaten during the current move. Once this number becomes strictly
 greater than the total size of candies eaten by the other player on their previous move, the current player stops eating 
 and the move ends. In other words, on a move, a player eats the smallest possible number of candies such that the sum of the sizes of candies eaten on this move is strictly greater than the sum of the sizes of candies that the other player ate on the previous move. If there are not enough candies to make a move this way, then the player eats up all the remaining candies and the game ends.

For example, if n=11 and a=[3,1,4,1,5,9,2,6,5,3,5], then:

move 1: Alice eats one candy of size 3 and the sequence of candies becomes [1,4,1,5,9,2,6,5,3,5].
move 2: Alice ate 3 on the previous move, which means Bob must eat 4 or more. Bob eats one candy of size 5 and the sequence
 of candies becomes [1,4,1,5,9,2,6,5,3].
move 3: Bob ate 5 on the previous move, which means Alice must eat 6 or more. Alice eats three candies with the total size of
 1+4+1=6 and the sequence of candies becomes [5,9,2,6,5,3].
move 4: Alice ate 6 on the previous move, which means Bob must eat 7 or more. Bob eats two candies with the total size of 3+5=8 
and the sequence of candies becomes [5,9,2,6].
move 5: Bob ate 8 on the previous move, which means Alice must eat 9 or more. Alice eats two candies with the total size of 5+9=14
 and the sequence of candies becomes [2,6].
move 6 (the last): Alice ate 14 on the previous move, which means Bob must eat 15 or more. It is impossible, so Bob eats the two
 remaining candies and the game ends.
Print the number of moves in the game and two numbers:

a — the total size of all sweets eaten by Alice during the game;
b — the total size of all sweets eaten by Bob during the game.


*/
void solve(ll a[],ll n)
{
	ll i,j,k,l,p=0LL,q=0LL;
	i=0;
	j=n-1;
	ll cpy=0;
	bool f=1;
	ll ch=0;
	while(i<=j)
	{
		ll sum=0;
		if(f)
		{
			// cout<<"\nAlice ch\n"<<" cpy = "<<cpy<<" i = "<<i<<" j = "<<j<<endl;
			while(i<=j&&sum<=cpy)
			sum+=a[i++];
			
			p+=sum;
			// cout<<"sum = "<<sum<<" p = "<<p<<endl;
			cpy=sum;
			ch++;
			// cout<<"ch = "<<ch<<endl;
			
		}
		else
		{
		    ch++;
		    // cout<<"ch = "<<ch<<endl;
		    // cout<<"\nBOB ch\n"<<" cpy = "<<cpy<<" i = "<<i<<" j = "<<j<<endl;
			while(j>=i&&sum<=cpy)
			sum+=a[j--];

		
			q+=sum;
			// cout<<"sum = "<<sum<<" q = "<<q<<endl;
			cpy=sum;
		}
		
		f=!f;
	}
	cout<<ch<<" "<<p<<" "<<q<<endl;
	
}
int main() {
	ll i,j,k,l,n,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll a[n];
		for(i=0;i<n;i++) cin>>a[i];
		solve(a,n);
	}
	// your code goes here
	return 0;
}