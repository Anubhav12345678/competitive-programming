#include<bits/stdc++.h>
using  namespace std;
int main(){
	int i,j,k,l,n,t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		n = s.size();
		int cnt=0;
		l=0;
		int r=  n-1;
		char a,b,c,d;
		while(l<r){
			if(s[l]!=s[r])
			{
				cnt++;
				if(cnt==1)
				a=s[l], b=s[r];
				else if(cnt==2)
				c=s[l], d=s[r];
				else break;
			}
			l++;
			r--;
		}
		if(cnt>2) cout<<"No\n";
		else if(cnt==2){
			if((a==c||b==d)||(a==d||b==c)) cout<<"Yes\n";
			else cout<<"No\n";
		}
		else if(cnt==1){
			if(n%2==0) cout<<"No\n";
			else if((s[n/2]==a)||  (s[n/2]==b)) cout<<"Yes\n";
			else cout<<"No\n";
		}
		else cout<<"Yes\n";
	}






	return 0;
}














