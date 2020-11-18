#define ll long long
#define pb push_back

class Solution {
public:
    long long int s;
    vector<long long int> v;
    void fill()
    {
        long long int a = 1LL,b=1LL;
        v.pb(a);
        v.pb(b);
        long long int c = a+b;
        while(c<=s)
        {
            v.pb(c);
            // long long int 
            a=b;
            b=c;
            c=a+b;
        }
        // while()
    }
    int findMinFibonacciNumbers(int k) {
        s = (long long int)k;
        int i,j,l;
        v.clear();
        fill();
        int n  =v.size();
        for(i=0;i<n;i++) cout<<v[i]<<" ";
        cout<<endl;
        i=n-1;
        int cnt=0;
        while(s>0&&i>=0)
        {
            cout<<"v["<<i<<" ] ="<<v[i]<<endl;
            if(s-v[i]>=0)
            {
                cout<<"en\n";
            s-=v[i];
                cnt++;
            }
            i--;
            // cnt++;
        }
        
        return cnt;
        
    }
};