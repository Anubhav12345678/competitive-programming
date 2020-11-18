
/*
Phoenix has a string s consisting of lowercase Latin letters. He wants to distribute all the letters of his 
string into k non-empty strings a1,a2,…,ak such that every letter of s goes to exactly one of the strings ai.
 The strings ai do not need to be substrings of s. Phoenix can distribute letters of s and rearrange the letters
  within each string ai however he wants.

For example, if s= baba and k=2, Phoenix may distribute the letters of his string in many ways, such as:

ba and ba
a and abb
ab and ab
aa and bb
But these ways are invalid:

baa and ba
b and ba
baba and empty string (ai should be non-empty)
Phoenix wants to distribute the letters of his string s into k strings a1,a2,…,ak to minimize the lexicographically 
maximum string among them, i. e. minimize max(a1,a2,…,ak). Help him find the optimal distribution and print the minimal 
possible value of max(a1,a2,…,ak).

String x is lexicographically less than string y if either x is a prefix of y and x≠y, or there exists an index 
i (1≤i≤min(|x|,|y|)) such that xi < yi and for every j (1≤j<i) xj=yj. Here |x| denotes the length of the string x.


*/


#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  sort(s.begin(),s.end());
  //if smallest k letters are not all the same, answer is kth smallest letter
  if (s[0]!=s[k-1]){
    cout<<s[k-1]<<endl;
    return;
  }
  cout<<s[0];
  //if remaining letters aren't the same, we append remaining letters to answer
  if (s[k]!=s[n-1]){
    for (int i=k;i<n;i++)
      cout<<s[i];
  }
  else{
    //remaining letters are the same, so we distribute evenly
    for (int i=0;i<(n-k+k-1)/k;i++)
      cout<<s[n-1];
  }
  cout<<endl;
}

int main(){
  int t; cin>>t;
  while (t--)
    solve();
}