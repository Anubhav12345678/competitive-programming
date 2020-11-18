#include<bits/stdc++.h>
using namespace std;
int sort(int a[],int n)
{
   int i,j,temp;
   for(i=0;i<n;i++)
   	for(j=0;j<n;j++)
   	{
   		if(a[j+1]>a[j])
   		{
   			temp=a[j];
   			a[j] = a[j+1];
   			a[j+1] = temp;
   		}
   	}
}
int main()
{
	int n,i,j,t=0,max=-1,s=0;
	scanf("%d",&n);
    int p[n],deadlines[n];
    for(i=0;i<n;i++)
    	scanf("%d",p+i);
    for(i=0;i<n;i++)
    {
    	scanf("%d",deadlines+i);
    	if(deadlines[i]>max)
    		max=deadlines[i];
    }
    sort(p,n);
    for(i=0;i<n;i++)
    {
    	if(t<max&&t<deadlines[i])
    	{
    		s+=p[i];
    		t++;
    	}
    }
    printf("%d\n",s);
}