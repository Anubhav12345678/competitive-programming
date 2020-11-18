#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,i,j,k,l,x,t,p,r;
	cin>>t;
	while(t--){
		cin>>n;
		r = n%4;
		k=n/4;
		string s="";
		while(k--)
		s+="8";
		if(r!=0)
		s+="8";
		int rem = n-s.size();
		for(i=0;i<rem;i++)
		s+="9";
		reverse(s.begin(),s.end());
		cout<<s<<endl;
	}
	// your code goes here
	return 0;
}
/*
Captain Flint and his crew keep heading to a savage shore of Byteland for several months already, drinking rum and telling stories. In such moments uncle Bogdan often remembers his nephew Denis. Today, he has told a story about how Denis helped him to come up with an interesting problem and asked the crew to solve it.

In the beginning, uncle Bogdan wrote on a board a positive integer x consisting of n digits. After that, he wiped out x and wrote integer k instead, which was the concatenation of binary representations of digits x consists of (without leading zeroes). For example, let x=729, then k=111101001 (since 7=111, 2=10, 9=1001).

After some time, uncle Bogdan understood that he doesn't know what to do with k and asked Denis to help. Denis decided to wipe last n digits of k and named the new number as r.

As a result, Denis proposed to find such integer x of length n that r (as number) is maximum possible. If there are multiple valid x then Denis is interested in the minimum one.

All crew members, including captain Flint himself, easily solved the task. All, except cabin boy Kostya, who was too drunk to think straight. But what about you?

Note: in this task, we compare integers (x or k) as numbers (despite what representations they are written in), so 729<1999 or 111<1000.

*/