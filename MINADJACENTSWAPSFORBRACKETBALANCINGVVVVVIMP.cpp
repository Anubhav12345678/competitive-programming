#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#include<vector>
// tc: o(n)
// sc: o(n)
ll solve(string &s){
	ll i,j,k,l,n=s.size();
	vector<ll> pos;
	for(i=0;i<n;i++)
	if(s[i]=='[') pos.pb(i);
	ll ans=0;
	ll cnt=0,p=0;
	for(i=0;i<n;i++){
		if(s[i]=='['){
			p++;
			cnt++;
		}
		else
		cnt--;
		if(cnt<0){
			ans+=pos[p]-i;
			swap(s[pos[p]],s[i]);
			p++;
			cnt=1;
		}
	}
	return ans;
}
int main() {
	
	string s;
	cin>>s;
	cout<<solve(s);
	// your code goes here
	return 0;
}

//const space sol
// Java Program to count swaps required to balance string 
public class BalanceParan 
{ 
	
	static long swapCount(String s) 
	{ 
		char[] chars = s.toCharArray(); 
		
		// stores total number of Left and Right 
		// brackets encountered 
		int countLeft = 0, countRight = 0; 
				// swap stores the number of swaps required 
		//imbalance maintains the number of imbalance pair 
		int swap = 0 , imbalance = 0; 
		
		for(int i =0; i< chars.length; i++) 
		{ 
			if(chars[i] == '[') 
			{ 
				// increment count of Left bracket 
				countLeft++; 
				if(imbalance > 0) 
				{ 
					// swaps count is last swap count + total 
					// number imbalanced brackets 
					swap += imbalance; 
					// imbalance decremented by 1 as it solved 
					// only one imbalance of Left and Right 
					imbalance--;	 
				} 
			} else if(chars[i] == ']' ) 
			{ 
				// increment count of Right bracket 
				countRight++; 
				// imbalance is reset to current difference 
				// between Left and Right brackets 
				imbalance = (countRight-countLeft); 
			} 
		} 
		return swap; 
	} 

// Driver code 
	public static void main(String args[]) 
	{ 
		String s = "[]][]["; 
		System.out.println(swapCount(s) ); 

		s = "[[][]]"; 
		System.out.println(swapCount(s) ); 
		
	} 
} 
// This code is contributed by Janmejaya Das. 
