#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cassert>

using namespace std;

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

#define MP make_pair
#define pb push_back

#define maxn 100000
#define maxd 1000000
#define maxt 50

typedef long long  LL;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
/*
Given an array A1,A2...AN, you have to print the size of the largest contiguous 
subarray such that LCM of all integers in that subarray is equal to the product of all integers in that subarray.
Formally,
For a subarray Ai,Ai+1...Aj where 1 ≤ i < j ≤ N to be valid: LCM(Ai,Ai+1...Aj) 
should be equal to Ai*Ai+1*...*Aj. You have to print the size of the largest valid subarray.

If no subarray satisfies output -1.

Note:A single element is not considered a subarray according to definition in this problem.
*/

vector<int> facts[maxd+1];
int arr[maxn+5];
int best[maxd+5];
int last[maxd+5];

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
   int i,j,k,n,q,T;

   // Generates the divisors
  for(i=2;i<=maxd;i++) if(facts[i].size()==0)
      for(j=i;j<=maxd;j+=i) facts[j].pb(i);


   scanf("%d",&T);
   assert(T>=1 && T<=maxt);

  while(T--)
  {
      scanf("%d",&n);
       assert(n>=2 && n<=maxn);

       MEM(last,-1);
       int ans=-1;



       for(i=0;i<n;i++)
       {
           scanf("%d",&arr[i]);
           assert(arr[i]>=1 && arr[i]<=maxd);

           int v=arr[i],x=-1;

           for(j=0;j<facts[v].size();j++)
           {
               int p=facts[v][j];
               if(last[p]!=-1) x=MAX(x,last[p]); // check the last time a prime factor p appeared in the array
               last[p]=i;
           }

          //  printf("%d %d\n",i,x);
           if(i)
           {
               best[i] = MAX(best[i-1],x);
               ans=MAX(ans,i-best[i]);
           }
           else
             best[i]=-1;
       }


     if(ans==1) ans=-1;
       printf("%d\n",ans);
  }


	return 0;
}

