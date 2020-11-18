#include <bits/stdc++.h>
using namespace std;
#define ll long long
int maxbitpos(int n)
{
	int res=-1;
	while(n)
	{
		n>>=1;
		res++;
	}
	return res;
}
int rangebitwiseand(int x,int y)
{
	int res=0;
	while(x>0&&y>0)
	{
		int m1 = maxbitpos(x);
		int m2 = maxbitpos(y);
		if(m1!=m2)
		break;
		int tmp = 1<<m1;
		res+=tmp;
		x-=tmp;
		y-=tmp;
	}
	return res;
}
int main() {
	int x=10,y=15;
	cout<<rangebitwiseand(x,y);
	
	// your code goes here
	return 0;
}