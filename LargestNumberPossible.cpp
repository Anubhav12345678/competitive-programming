#include <iostream>
using namespace std;
#include<string.h>
string solve(int n,int s)
{
    if(s>9*n||s==0)
    return "-1";
    string res="";
    while(s>=9&&res.size()<=n)
    {
        res+="9";
        s-=9;
    }
    res+=s+'0';
    if(res.size()<=n)
    {
        while(res.size()<n)
        res+="0";
    }
    return res;
}
int main() {
    int t,n,s;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        cout<<solve(n,s)<<endl;
    }
	//code
	return 0;
}