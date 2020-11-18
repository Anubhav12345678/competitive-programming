#include<bits/stdc++.h>
#define cases long long t;cin>>t;while(t--)
#define f_io ios::sync_with_stdio(false); cin.tie(0)
#define foi(a,n) for(long long i=a;i<n;i++)
#define foj(a,n) for(long long j=a;j<n;j++)
#define fok(a,n) for(long long k=a;k<n;k++)
#define ll long long
#define MOD 1000000007
#define INF 1000000000
using namespace std;
 
int main()
{
    f_io;
    ll n,m,q;
    cin >> n >> m >> q;
    vector<ll> x(n),y(m);
    foi(0,n)
        cin >> x[i];
    foi(0,m)
        cin >> y[i];
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    while(q--)
    {
        ll z,x1=0,x2=n,y1=0,y2=m,t1,t2,t3,t4;
        cin >> z;
        string s;
        cin >> s;
        if(s=="A")
        {
            cin >> t1 >> t2;
            x1 = lower_bound(x.begin(),x.end(),t1)-x.begin();
            x2 = upper_bound(x.begin(),x.end(),t2)-x.begin();
        }
        else if(s=="B")
        {
            cin >> t1 >> t2;
            y1 = lower_bound(y.begin(),y.end(),t1)-y.begin();
            y2 = upper_bound(y.begin(),y.end(),t2)-y.begin();
        }
        else
        {
            cin >> t1 >> t2 >> t3 >> t4;
            x1 = lower_bound(x.begin(),x.end(),t1)-x.begin();
            x2 = upper_bound(x.begin(),x.end(),t2)-x.begin();
            y1 = lower_bound(y.begin(),y.end(),t3)-y.begin();
            y2 = upper_bound(y.begin(),y.end(),t4)-y.begin();
        }
        ll ans = 0;
        ll right=y2-1;
        foi(x1,x2)
        {
            while(right>=y1 && x[i]+y[right]>z) right--;
            if(right<y1) break;
            ans += right-y1+1;
        }
        cout << ans << "\n";
    }
    return 0;
}

/*
After the death of Tony Stark now it's time for Morgon Stark to save the world. So she decided to build a data-centre in City. Assuming house of Morgon Stark at origin in 2D-plane she wants that distance of data-centre should be not more than Z from her house. But she has limited number of choices where she can build data-centre.She is interested to know that how many ways  she can choose a location for her data-centre.  So she gave her problem to you and asked for your help. Although you are not Dr. Strange , you  are Dr. Programmer so you can solve her problem.

You are given a set of X coordinates having length N  and a set of Y coordinates having length M  , find how many ways you can choose A point P(X0,Y0) from given set such that

X0 is one of the given X-coordinates.
Y0 is one of the given Y-coordinates.
 Manhattan distance of P(X0,Y0) is less than or equal to Z  . 
You are given 3 types of query

Z A L1 R1 :  you can choose X0 between [L1,R1] from given set of X cordinates and no restriction on Y0

Z B L2 R2 : you can choose Y0  between [L2,R2] from given set of Y cordinates and no restriction on X0

Z C L1 R1 L2 R2 :  you can choose X0  between [L1,R1] from given set of X cordinates  and Y0 between [L2,R2] from given set of Y cordinates


*/


















