#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<stack>
string solve(string s){
	int i,j,k,l,n=s.size();
	string res="";
    stack<int> st;
    for(i=0;i<=n;i++){
    	st.push(i+1);
    	if(i==n||s[i]=='N'){
    		while(!st.empty()){
    			res+=to_string(st.top());
    			st.pop();
    		}
    	}
    }
    return res;
}
int main() {
	string s;
	cin>>s;
	cout<<solve(s)<<endl;
	// your code goes here
	return 0;
}
/*
Given a sequence consisting of  and  where  denotes increasing sequence and ‘D’ denotes the decreasing sequence.
 Decode the given sequence to construct minimum number without repeated digits.
Given a sequence consisting of  and  where  denotes increasing sequence and ‘M’ denotes the
 decreasing sequence. Decode the given sequence to construct minimum number without repeated digits.

*/