#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include<limits.h>
ll int min(ll int a,ll int b){ return (a<b)?a:b; }
void createtree(ll int st[],ll int in,ll int low,ll int high,ll int a[])
{
	if(low==high)
	st[in]=a[low];
    else
    {
    	ll int mid = (low+high)/2;
    	createtree(st,2*in+1,low,mid,a);
    	createtree(st,2*in+2,mid+1,high,a);
    	st[in] = min(st[2*in+1],st[2*in+2]);
    }
}
ll int search(ll int st[],ll int ql,ll int qr,ll int low,ll int high,ll int pos)
{
	if(ql>high||qr<low)
	return INT_MAX;
	if(ql<=low&&qr>=high)
	return st[pos];
	ll int mid = (low+high)/2;
	ll x = search(st,ql,qr,low,mid,2*pos+1);
	ll y = search(st,ql,qr,mid+1,high,2*pos+2);
	return min(x,y);
}
void update(int st[],int i,int diff,int ss,int se,int si)//to update val in the seg tree-to add the differrence diff
{//this fun is for updating a single element not for a range for updating on a range we need to use updateRange fun
  /* A recursive function to update the nodes which have the given 
   index in their range. The following are parameters 
    tree[] --> segment tree 
    si     -->  index of current node in segment tree. 
                Initial value is passed as 0. 
    ss and se --> Starting and ending indexes of array elements  
                  covered under this node of segment tree. 
                  Initial values passed as 0 and n-1. 
    i    --> index of the element to be updated. This index  
            is in input array. 
   diff --> Value to be added to all nodes which have array 
            index i in range */
	if(i>se||i<ss)
		return;
	// now i lies in between ss and se we need to check whether ss and se are the same to know if it is a leaf
	st[si]+=diff;
	if(ss!=se)
	{
		int mid = (ss+si)/2;
		update(st,i,diff,ss,mid,2*si+1);
		update(st,i,diff,mid+1,se,2*si+2);
	}
}
/* Function to update segment tree for range update in input  
   array. 
    si -> index of current node in segment tree 
    ss and se -> Starting and ending indexes of elements for 
                 which current nodes stores sum. 
    us and ue -> starting and ending indexes of update query 
    diff -> which we need to add in the range us to ue */
void updateRange(int si,int ss,int se,int st[],int us,int ue,int diff)
{
	if(ss>se||ss>ue||se<us)
		return;
	if(ss==se)
		st[si]+=diff;
	else
	{
		int mid = (ss+si)/2;
		updateRange(2*si+1,ss,mid,st,us,ue,diff);
		updateRange(2*si+2,mid+1,se,st,us,ue,diff);
	}
}
//updaterange using lazy propogation so that it is faster
//this func is for the sg having sum of ele btwn a given range
void updateRangeUtil(int si,int ss,int se,int ue,int us,int diff,int st[],int lazy[])
{
	// If lazy value is non-zero for current node of segment 
    // tree, then there are some pending updates. So we need 
    // to make sure that the pending updates are done before 
    // making new updates. Because this value may be used by 
    // parent after recursive calls (See last line of this
	if(lazy[si]!=0)
	{
      st[si] += (se-ss+1)*lazy[si];
      if(ss!=si)
      {
      	lazy[2*si+1]+=lazy[si];
      	lazy[2*si+2]+=lazy[si];
      }
      lazy[si]=0;
	}

	//no overlap
	if(ss>se||ss>ue||se<us)
		return;
	//total overlap
	if(us<=ss&&ue>=se)
	{
		st[si]+=(se-ss+1)*diff;
		if(ss!=si)
		{
			lazy[2*si+1]+=lazy[si];
      	    lazy[2*si+2]+=lazy[si];
		}
		return;
	}
	//now we have a partial overlap
	int mid = (ss+se)/2;
	updateRangeUtil(2*si+1,ss,mid,ue,us,diff,st,lazy);
	updateRangeUtil(2*si+2,mid+1,st,ue,us,diff,st,lazy);

	//now as it is a sum finding range query
	st[si] = st[2*si+1] + st[2*si+2];
}
int getSumUtil(int ss,int se,int us,int ue,int si,int st[],int lazy[])
{
	if(lazy[si]!=0)
	{
		st[si]+=(se-ss+1)*lazy[si];
		if(ss!=si)
		{
			lazy[2*si+1]+=lazy[si];
			lazy[2*si+2]+=lazy[si];
		}
		lazy[si] = 0;
	}

    if(ss>se||ss>ue||se<us)
		return 0;
	//if total overlap then we can return the value
	if(ss>=us&&se<=ue)
		return st[si];
	int mid = (ss+se)/2;
	return getSumUtil(ss,mid,us,ue,2*si+1,st,lazy)+getSumUtil(mid+1,st,us,ue,2*si+2,st,lazy); 

}
int main() {
	ll int n,t,q,i,a[1000001],p,q2;
	cin>>n>>q;
	ll int st[4*n]={0};
	ll int lazy[4*n] = {0};
	for(i=0;i<n;i++)
	cin>>a[i];
	createtree(st,0,0,n-1,a);
	while(q--)
	{
		cin>>p>>q2;
		cout<<search(st,p-1,q2-1,0,n-1,0)<<endl;
	}
	// your code goes here
	return 0;
}