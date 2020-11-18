#include <bits/stdc++.h>
    #include <math.h>
 
    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    # define M_PI  3.14159265358979323846
 
 
    const int M=1e9+7;
    long long mod(long long x){
        return ((x%M + M)%M);
    }
    long long add(long long a, long long b){
        return mod(mod(a)+mod(b));
    }
    long long mul(long long a, long long b){
        return mod(mod(a)*mod(b));
    }
    /*
Consider the following process. You have a binary string (a string where each character is either 0 or 1) w of length 
n and an integer x. You build a new binary string s consisting of n characters. The i-th character of s is chosen as follows:

if the character wi−x exists and is equal to 1, then si is 1 (formally, if i>x and wi−x= 1, then si= 1);
if the character wi+x exists and is equal to 1, then si is 1 (formally, if i+x≤n and wi+x= 1, then si= 1);
if both of the aforementioned conditions are false, then si is 0.
You are given the integer x and the resulting string s. Reconstruct the original string w.


    */
 
    void solve(){
        string s;
        cin>>s;
        int x;
        cin>>x;
        int n=s.size();
        string w(n,'1');
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(i-x>=0)
                    w[i-x]='0';
                if(i+x<n)
                    w[i+x]='0';
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                if((i-x>=0 && w[i-x]=='1')||(i+x<n && w[i+x]=='1'))
                    continue;
                else{
                    cout<<-1<<"\n";
                    return;
                }
            }
            else{
                if((i-x>=0 && w[i-x]=='1')||(i+x<n && w[i+x]=='1')){
                    cout<<-1<<"\n";
                    return;
                }
            }
        }
        cout<<w<<"\n";
    }
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout<<fixed;
        cout<<setprecision(10);
//        freopen("timber_input.txt", "r", stdin);
//        freopen("timber_output.txt", "w", stdout);
        int t=1;
        cin>>t;
        for(int i=1;i<=t;i++){
//            cout<<"Case #"<<i<<": ";
            solve();
        }
        return 0;
    }