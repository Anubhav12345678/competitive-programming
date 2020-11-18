void swap(int *a,int *b)
{
	int t= *a;
	*a = *b;
	*b = t;
}
int partition(int a[],int low,int high)// returns correct position of the pivot
{
	int pivot = a[high];
	int i = low-1;
	for(j=low;j<=high-1;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(&a[i],&a[j]);
		}
	}
	// 0 se i tk pivot se chote sare ele aa chuke hai
    swap(&a[i+1],&a[low]);
    return i+1;
}
void quicksort(int a[],int low,int high)
{
	int pi = partition(a,low,high);
	quicksort(a,low,pi);// applying quicksort on left array of pivot
	quicksort(a,pi+1,high);// applying quicksort on right array of pivot
}
int main()
{
	int t,n,a[100005],i,j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];
		quicksort(a,0,n-1);
		for(i=0;i<n;i++)
			cout<<a[i]<<" ";
	}
}
