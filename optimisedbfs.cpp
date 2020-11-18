#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include<vector>
#define pb push_back
#include<map>
#include<iterator>
#include<map>
#include<string.h>
#include<set>
#include<queue>
#define pq priority_queue
#define mx 1000005
vector<int> V[10];
bool vis[mx];
ll d[mx];
int main() {
	queue<int> Q;
	string s;
	ll sz,i,j,idx,val;
	cin>>s;
	sz = s.size();
	d[0] = 0;
	memset(vis,false,sizeof(vis));
	vis[0] = true;
	for(i=1;i<sz;i++)
	{
		val = s[i]-'0';
		V[val].pb(i);
	}
	Q.push(0);
	while(!Q.empty())
    {
    	idx = Q.front();
    	//cout<<"idx = "<<idx<<endl;
    	if(idx==sz-1)
    	break;
    	Q.pop();
    	
    	val = s[idx]-'0';
    //	cout<<"val = "<<val<<endl;
    	ll vdz = V[val].size();
    	//cout<<"vdz = "<<vdz<<endl;
    	for(j=0;j<vdz;j++)
    	{
    		if(!vis[V[val][j]])
    		{
    			//cout<<"V["<<val<<"]["<<j<<"] = "<<V[val][j]<<endl;
    			vis[V[val][j]] = true;
    			Q.push(V[val][j]);
    			d[V[val][j]] = d[idx]+1;
    			//cout<<"d[V["<<val<<"]["<<j<<"]] = "<<d[V[val][j]]<<endl;
    		}
    	}
    	V[val].clear();
    	if(idx-1>=0&&!vis[idx-1])
    	{
    		vis[idx-1] = true;
    		Q.push(idx-1);
    		d[idx-1] = d[idx]+1;
    		//cout<<"d["<<idx-1<<"] = "<<d[idx-1]<<endl;
    	}
    	if(idx+1<sz&&!vis[idx+1])
    	{
    		vis[idx+1] = true;
    		Q.push(idx+1);
    		d[idx+1] = d[idx]+1;
    		//cout<<"d["<<idx+1<<"] = "<<d[idx+1]<<endl;
    	}
    }
    
    cout<<d[sz-1]<<endl;
	
	
	// your code goes here
	return 0;
}