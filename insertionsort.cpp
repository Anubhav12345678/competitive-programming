void insertionsort(int a[],int n)
{
	int i,j,key;
	//loop from 1 to nof i and then insert a[i] into the sorted sequence of  
	for(i=1;i<n;i++)
	{
		key = a[i];
		j=i-1;
		while(j>=0&&a[j]>key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
}