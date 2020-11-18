#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define ll long long




// view https://ideone.com/DyrU4T for complete code & output
void printArray (ll arr[], ll n) 
{ 
    for (ll i = 0; i < n; i++) 
        printf("%lld ", arr[i]); 
    printf("\n"); 
}
void swap(ll *a,ll *b)
{
	ll t = *a;
	*a=*b;
	*b = t;
}
void randomize(ll a[],ll n)
{
	// Use a different seed value so that we don't get same 
    // result each time we run this program 
	srand(time(NULL));
	for(ll i=n-1;i>0;i--)
	{
		// Pick a random index from 0 to i 
		ll j=rand()%(i+1);
		//swap a[i] with the ele at random index
		swap(&a[i],&a[j]);
	}
}
int main() {
	ll arr[] = {1, 2, 3, 4, 5, 6, 7, 8}; 
    ll n = sizeof(arr)/ sizeof(arr[0]); 
    randomize (arr, n); 
    printArray(arr, n); 
  
    return 0;
	// your code goes here
	return 0;
}