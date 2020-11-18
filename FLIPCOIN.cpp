#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define INF LLONG_MAX
#define mx 1000005
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define ll long long
ll A[mx]={0};
ll tree[mx]={0};
ll N;
ll lazy[mx] = {0};
ll sum(ll a,ll b)
{
	return (a+b);
}
ll zero()
{
	return 0;
}
void build(ll node=1,ll start=0,ll end=N-1)
{
	if(start==end)
	{
		tree[node] = A[start];
		return;
	}
	else
	{
		ll mid = (start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		
		tree[node] = sum(tree[2*node],tree[2*node+1]);
	}
}

void propogatelazy(ll node,ll left,ll right)
{
	if(lazy[node]!=0)
	{
		//cout<<"\nnow lazy propogate starts with left="<<left<<" node="<<node<<" right="<<right<<"\n\n\n";
		tree[node] = (right-left+1)-tree[node];
		//cout<<"\n\n\ntree["<<node<<"] = "<<tree[node]<<"\n\n\n";
		if(right!=left)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node]%=2;
			lazy[2*node+1]+=lazy[node];
			lazy[2*node+1]%=2;
			//cout<<"\n\n\n"<<"lazy["<<2*node<<"] = "<<lazy[2*node]<<"\n\n\n";
			//cout<<"\n\n\n"<<"lazy["<<2*node+1<<"] = "<<lazy[2*node+1]<<"\n\n\n";
		}
		lazy[node]=0;
	//	cout<<"\nnow lazy propogate ends\n";
	}
}

void update(ll ql,ll qr,ll start=0,ll end=N-1,ll node=1)
{
//	cout<<"\nnow update function starts with start = "<<start<<" end="<<end<<" node="<<node<<"\n";
	propogatelazy(node,start,end);
	if(ql>end||qr<start||end<start)
	return;
	else if(ql<=start&&qr>=end)//total overlap
	{
		lazy[node]+=1;
		lazy[node]%=2;
	//	cout<<"\n\n\nlazy["<<node<<"] = "<<lazy[node]<<"\n\n\n";
		propogatelazy(node,start,end);
		return;
	}
	else
	{
		ll mid = (start+end)/2;
		update(ql,qr,start,mid,2*node);
		update(ql,qr,mid+1,end,2*node+1);
		tree[node] = sum(tree[2*node],tree[2*node+1]);
		//cout<<"\n\n\ntree["<<node<<"] = "<<tree[node]<<"\n\n\n";
	}
}

ll query(ll ql,ll qr,ll start=0,ll end=N-1,ll node=1)
{
//	cout<<"\n\n\nnow query fun starts with start="<<start<<" end="<<end<<" node="<<node<<"\n\n\n";
	propogatelazy(node,start,end);
	if(ql>end||qr<start||start>end)
	return 0;
	else if(ql<=start&&qr>=end)
	{
		return tree[node];
	}
	else
	{
		ll mid = (start+end)/2;
		return sum(query(ql,qr,start,mid,2*node),query(ql,qr,mid+1,end,2*node+1));
	}
}


int main() {
	ll x,y,i,j,k,a,b,t;
	fastIO
	memset(A,0,sizeof(A));
	cin>>N>>t;
	build();
	while(t--)
	{
		cin>>x>>a>>b;
		if(x==0)
		{
			update(a,b);
		}
		else
		{
			cout<<query(a,b)<<endl;
		}
	}
	
	
	
	// your code goes here
	return 0;
}