#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
//You are given a string  that is made of lowercase English alphabets. Determine the length of the smallest substring that
 // contains the maximum number of distinct characters.

Input format
#define pb push_back
ll chk(ll f[30], ll mx){
	ll temp = 0;
	for(ll i=0; i<26; i++)if(f[i])temp++;
	return (temp==mx);
}
int main(){
   ll i,j,k,l,n;
   string s;
   cin>>s;
   n = s.size();
    ll dis[30]={0};
    for(i=0;i<n;i++) dis[s[i]-'a']=1;
    ll mx = 0;
    ll ans=1;
    for(i=0;i<26;i++) mx+=dis[i];
    ll lo=1;
    ll hi=n;
    while(lo<=hi){
       ll m= (lo+hi)/2;
       ll f[30]={0};
       ll fg=0;
       for(i=0;i<m;i++) f[s[i]-'a']++; 
       for(j=1;j<=n-m;j++){
          if(chk(f,mx))
          {
             fg=1;
             break;
          }
          f[s[j-1]-'a']--;
          f[s[j+m-1]-'a']++;
       }
       if(chk(f,mx)) fg=1;
       if(fg){
          ans = m;
          hi=m-1;
       }
       else
       lo=m+1;

    }
    cout<<ans<<endl;
     return 0;	   
   }




















