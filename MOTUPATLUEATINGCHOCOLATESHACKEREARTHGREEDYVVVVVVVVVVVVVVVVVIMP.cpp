#include <bits/stdc++.h>
using namespace std;
#define ll long long 
long long mod=1000000007;
/*
Motu and Patlu are very good friends and they love to eat ice-creams. Once they thought of playing a game,
 so they bought “n” ice-creams from the market of varying heights (may be same). They arranged the ice-creams
  in a line in random order. Motu starts to eat ice-creams from left to right and Patlu from right to left. 
  The heights of the ice-creams are known.

Motu eats the ice-cream as twice the speed of Patlu (that’s the secret for his health :p ). If, anyone of them
 is eating the ice-cream , then definitely other one cannot have that ice-cream. However, if both of them reach
  the same ice-cream, Motu snatches it away from Patlu (he got more power than patlu :( ) and eats it. The winner
   will be the one who will eat more number of ice-creams.

Since, both of them are too busy in eating ice-creams they forgot to count the number of ice-creams they have 
already eaten. Can you help them in deciding the winner.

P.S.- Since, ‘WINTER HAS ALREADY ARRIVED’ ,so ice-creams will not melt as it is freezing out there.

*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        ll i=0,j=n-1,sum1=0,sum2=0;
        if(n==1)
        {
            cout<<"1 0"<<endl;
            cout<<"Motu"<<endl;
        }
        else
        {
            int flag=0;
            sum1=0;sum2=0;
            while(i<=j)
            {
                if(sum1<=(2*sum2))
                {
                    while((sum1<=2*sum2)&&i<=j)
                    {
                        sum1+=a[i];
                        i++;
                    }
                }
                else
                if(sum1>sum2)
                {
                    while((sum1>2*sum2)&&j>=i)
                    {
                        sum2+=a[j];
                        j--;
                    }
                }
            }
            ll p,q;
            p=i;q=n-j-1;
            cout<<p<<" "<<q<<endl;
            if(p>q)
            cout<<"Motu"<<endl;
            else
            if(q>p)
            cout<<"Patlu"<<endl;
            else
            cout<<"Tie"<<endl;
        }
    }
    return 0;
}