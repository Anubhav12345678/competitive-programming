int last(int a[],int l,int h)
{
	if(h<l)
		return -1;
	int m = (l+h)/2;
	if(m<h&&a[m]==1&&a[m+1]==0)
		return m;
	if(m>l&&a[m-1]==1&&a[m]==0)
		return m-1;
	if(a[m]==1)
		return last(a,m+1,h);
	return last(a,l,m-1);
}
int solve(int mat[R][C])
{
	int maxrowind=0;
	int j = last(mat[0],0,C-1);
	if(j==-1)
		j=0;
	for(i=0;i<R;i++)
	{
		while(j<n&&mat[i][j]==1)
		{
			j++;
			maxrowind=i;
		}
	}
	return maxrowind;
}