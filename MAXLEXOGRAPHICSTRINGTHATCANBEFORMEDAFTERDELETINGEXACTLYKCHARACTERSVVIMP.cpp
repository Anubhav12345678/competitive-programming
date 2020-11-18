#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#include<stack>
#include<queue>
#define pb push_back
// #define pf pop_back
/*
Smriti is learning about strings in school and asks her best friend, Stephanie, to give her a practice problem.

Stephanie gives Smriti a string S of length N, and a positive integer m (where m<n). Smriti must delete exactly m
 characters from the String such that the resultant string is lexicographically largest (last when ordered alphabetically). 
 Solve the challenge along with Smriti so she can check her answer!


*/
void solve(string s,ll K){
    ll i,j,k,l,n=s.size();
     deque<char> q;
    ll cnt=0;
    for(i=0;i<n;i++){
        while(q.size()>0&&(q.back()<s[i])&&cnt<K){
            cnt++;
            q.pop_back();
        }
        q.push_back(s[i]);
    }
    string res="";
    while(q.size()>0&&res.size()<(n-K)){
        res+=q.front();
        q.pop_front();
    }
    
    cout<<res<<endl;
}
int main() {
    ll t,i,j,k,l,n;
    cin>>t;
    while(t--){
        string s;
        cin>>s>>k;
        solve(s,k);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
