#include <bits/stdc++.h>
using namespace std;
 
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
 
	    vector<vector<int> > dp(n+1,vector<int>(1+n,0));
 
	    for(int i=0;i<n;i++)dp[i][i]=1;
	    int ans=0;
	    for(int L=2;L<n+1;L++)
	    {
	        for(int i=0;i<n-L+1;i++)
	        {
	            int j = i+L-1;
	            if(s[i]==s[j] and L==2)
	            {
	                dp[i][j]=2;
	                ans++;    
	            }
	            else if(s[i]==s[j] and L>2 and dp[i+1][j-1]>0)
	            {
	                ans++;
	                dp[i][j]=dp[i+1][j-1]+2;
	            }
	        }
	    }
	    cout<<ans<<endl;
 
 
 
 
	}
	return 0;
}