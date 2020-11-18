#include<bits/stdc++.h>
using namespace  std;
#define ll long long
#include<map>
#define ff first
#define se second
/*
Golu loves travelling. So this time he has planned to go to Europe. He will write down the place he is going
 to visit and amount of money spent on that trip. Each of the move was written on a card in the order he visits 
 the cities. If we visits the cities A,B,C,D in this order then he will write it down like this on his cards with 
 the money he spent on that trip:
A B 10
B C 20
C D 5
D A 100
As he was a great planner he would never visit a place twice. Before starting his journey his cards got shuffled.
 Now he cannot remember the actual order of cards. Can you help him to do so?

Input
The first line contains an integer T, the number of test cases. Each case starts with the value of N the number of
 cities he is going to visit. The next lines N-1 lines are of the form
A B C
Where A,B are the cities and C the amount spent on the that trip



*/
int main(){
	ll t,i,j,k,l,n,m;
    cin>>t;
	while(t--){
		unordered_map<string,pair<string,ll>> left;
		unordered_map<string,pair<string,ll>> right;
        ll tot=0;
		cin>>n;
		for(i=0;i<n-1;i++){
			string s1,s2;
            ll c;
			cin>>s1>>s2>>c;
			left[s2] = {s1,c};
			right[s1]= {s2,c};
			tot+=c;
		}

		string src,dest;
		for(auto it = left.begin();it!=left.end();it++)
		{
			if(right.find(it->ff)==right.end())
			{
				dest=it->ff;
				break;
			}
		}
		for(auto it=right.begin();it!=right.end();it++){
			if(left.find(it->ff)==left.end()){
				src = it->ff;
				break;
			}
		}

		if(right.size()!=0){
			while(true){
				cout<<src<<" "<<right[src].ff<<" "<<right[src].se<<endl;
				src = right[src].ff;
				if(src==dest) break;
			}
		}
		cout<<tot<<endl;
	}
}