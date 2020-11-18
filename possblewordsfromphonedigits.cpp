#include<bits/stdc++.h>
using namespace std;
string str[9]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int N;
void words(string w,int dig[], int i)
{
    if(i==N)
    {
        cout<<w<<" ";
        return;
    }
    
    for(int j=0;j<str[dig[i]-2].size();j++)
    {
        w+=str[dig[i]-2][j];
        words(w,dig,i+1);
        w.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
	int i,j,T;
	cin>>T;
	
	while(T--)
	{
	    cin>>N;
	    int d[N];
	    
	    for(i=0;i<N;i++)
	        cin>>d[i];
	    words("",d,0);
	    cout<<"\n";
	}
	
	return 0;
}