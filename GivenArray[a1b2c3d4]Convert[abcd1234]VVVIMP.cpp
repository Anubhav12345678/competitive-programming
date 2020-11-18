#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool comp(char a,char b)
{
	return a<b;
}
void change(string s)
{
	int n = s.size();
	int i,j,k,l;
	sort(s.begin(),s.end(),comp);
	cout<<s<<endl;
	for(i=0;i<n;i++)
	if(s[i]>='a'&&s[i]<='z')
	break;
	j=0;
	cout<<i<<endl;
	string p = s.substr(0,i);
	string q = s.substr(i);
	reverse(p.begin(),p.end());
	reverse(q.begin(),q.end());
	cout<<"p="<<p<<endl;
	cout<<"q="<<q<<endl;
	s=p+q;
	reverse(s.begin(),s.end());
	cout<<s<<endl;
}
int main() {
	change("a1b2c3d4e5f6g7h8i9");
	// your code goes here
	return 0;
}

//OUTPUT abcdefghi123456789