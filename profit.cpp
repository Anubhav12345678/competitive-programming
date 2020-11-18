#include<bits/stdc++.h>
using namespace std;
int max(int a,int b){ return (a>b)?a:b;}
int maxprofit(int p[],int w[],int limitwght,int index,int n,int x[])
{
	
	if(limitwght<=0)
		return 0;
	if(limitwght<w[index])
	return maxprofit(p,w,limitwght,index+1,n,x);
	if(index>=n)
		return 0;
    int u = p[index]+maxprofit(p,w,limitwght-w[index],index+1,n,x);
    int y = maxprofit(p,w,limitwght,index+1,n,x);
    if(u>y)
    {
        x[index] = 1;
        return u;
    }
    else
    {
        x[index]=0;
        return y;
    }
	
}
int  main()
{
	int n,p[10001],w[10001],i,maxwght;
	scanf("%d%d",&n,&maxwght);
	int x[n] = {0};
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
  printf("%d\n",maxprofit(p,w,maxwght,0,n,x));
  for(i=0;i<n;i++)
  printf("%d ",x[i]);
}