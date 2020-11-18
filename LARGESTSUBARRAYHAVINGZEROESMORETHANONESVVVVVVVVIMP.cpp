#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
/*
Explanation of the author's code:
We have four arrays-
1. zero[], zero[i]=store the count of 0 upto index i.
2. one[], one[i]=store the count of 1 upto index i.
3. temp[], temp[i] = zero[i] - one[i]; this array store the difference of zeroes and ones upto index i.
4. Mini[], mini[i]=store the minimum value of temp, upto to index i.
------------------------------------------------------------------------------------------------------------------------------------------------------
Let’s take an example, make some observations-
s=”11000101”
zero[]= {0, 0, 1, 2, 3, 3, 4, 4}
one[] = {1, 2, 2, 2, 2, 3, 3, 4}
temp[]={-1, -2, -1, 0, 1, 0, 1, 0}
mini[]={-1, -2, -2, -2, -2, -2, -2, -2}

Now let’s suppose any subarray having left indx=l, and right index=r
This subarray will have no. of zero> no. of ones only iff, temp[l-1]<temp[r].

So using the above observation, we will try to find the largest subarray ending at index i, having count of zeros>count
 of ones. And finally we will take the maximum among all subarrays.

So for that we can do binary search.
For example, we want to find the max length subarray ending at index=5 (0-based indexing) having cnt of ones>cnt of zeros.
So for that we want to find the minimum index l, such that temp[l]<temp[5], and if we find such an index, then the
 maximum subarray ending at index 5 will be =5-l. So repeat the same process for all indexes. And take the maximum among all.


*/
   ll i,j,k,l,n,t;
   string s;
   cin>>n>>s;
   s = " "+s;
   ll en=0,st=0,cnt=0,ans=0;
   ll tmp[n+1]={0},z[n+1]={0},o[n+1]={0};
   ll mini[n+1];
   memset(mini,0,sizeof(mini));
//    mini[0] = 0;
   for(i=1;i<=n;i++){
	   o[i] = o[i-1];
	   z[i] = z[i-1];
      if(s[i]=='0') z[i]++;
	  else
	  o[i]++;
	  tmp[i]  =z[i]-o[i];
	  mini[i] = min(mini[i-1],tmp[i]);
   }

   for(i=1;i<=n;i++){
		  ll lo=0;
		  ll hi = i;
		  // max subarray ending at i having cnt[0]>cnt[1]
		  while(lo<=hi){
			  ll mid = (lo+hi)/2;
			  if(mini[mid]<tmp[i]) 
			  {
				  ans = max(ans,i-mid);
				  hi = mid-1;
			  }
			  else
			  lo=mid+1;
		  }
	  }

   cout<<ans<<endl;














	return 0;
}















