#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;




//better way


// bool isprime[3000005];
// void fill(int n)
// {
//     memset(isprime,true,sizeof(isprime));
//     int i,j,k,l;
//     isprime[0]=isprime[1]=0;
//     for(i=2;i*i<=n;i++)
//     {
//         for(j=i*i;j<=n;j+=i)
//         isprime[j]=0;
//     }
// }
bool isPrime(int n){
if(n<=1)
return false;
if(n<=3)
return true;
if(n%2==0 || n%3==0)
return false;
for(int i=5; i<=sqrt(n); i=i+6){
if(n%i==0 || n%(i+2)==0)
return false;
} return true;
}



vector<int> Solution::primesum(int A) {
    vector<int> res(2);
    int i,j,k,l;
    // fill(A);
    for(i=2;i<=A/2;i++)
    {
        if(isPrime(i)&&isPrime(A-i))
        return {i,A-i};
    }
    return {};
}

//A prime number is Super Prime if it is a sum of two primes. Find all the Super Primes upto N
bitset<10000007> prime;
vector<ll> s;
void Sieve()
{
    prime[0]=1;
    prime[1]=1;
   for(ll i=2;i*i<=10000007;i++)
   {
       if(prime[i]==0)
       {
           for(ll j=i*2;j<=10000007;j+=i)
               prime[j]=1;
       }
   }
   for(ll i=2;i<=10000007;i++)
   {
       if(prime[i]==0 && prime[i-2]==0)
       s.push_back(i);
   }
}

int main()
 {
    ll t;
    cin>>t;
    Sieve();
    while(t--)
    {
         ll n;
         cin>>n;
         ll c=upper_bound(s.begin(),s.end(),n)-s.begin();
         cout<<c<<endl;
    }
    return 0;
}