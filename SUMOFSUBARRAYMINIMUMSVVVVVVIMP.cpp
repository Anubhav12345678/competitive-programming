class Solution {
public:


#define ll long long
static ll mod = 1e9+7;
class Solution {
public:
    
    int sumSubarrayMins(vector<int>& A) {
        ll i,j,k,l,n=A.size();
        stack<ll> st;
        ll ans=0LL;
        A.push_back(INT_MIN);
        for(i=0;i<A.size();i++)
        {
            while(!st.empty()&&A[st.top()]>A[i])
            {
                ll m = st.top();
                st.pop();
                ll x;
                if(st.size())
                    x = (m-st.top());
                else
                    x=m+1LL;
                ll y = (i-m);
                ans+=(x*y*A[m]);
                // ans = (ans+(m-(st.empty()?-1:st.top()))*(i-m)*A[m])%mod;
            }
            st.push(i);
        }
        return ans%mod;
    }
};














    int sumSubarrayMins(vector<int>& A) {
        int i,j,k,l,n=A.size();
        long long int ans=0;
        int m= 1000000007;
        long long int left[n],right[n];
        stack<pair<int,int>> st1,st2;
        for(i=0;i<n;i++)
        {
            long long int cnt=1;
            while(!st1.empty()&&st1.top().first>A[i])
            {
                cnt+=st1.top().second;
                st1.pop();
            }
            st1.push({A[i],cnt});
            left[i] = cnt;
        }
        for(i=n-1;i>=0;i--)
        {
           long long int cnt=1;
            while(!st2.empty()&&st2.top().first>=A[i])
            {
                cnt+=st2.top().second;
                st2.pop();
            }
            st2.push({A[i],cnt});
         right[i] = cnt; 
        }
        
        for(i=0;i<n;i++)
        {
            ans = (ans+A[i]*left[i]*right[i])%m;
        }
        return ans;
        
    }
};