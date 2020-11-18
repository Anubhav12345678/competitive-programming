#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*
An important meeting is going to start soon in an office on a round table (Not like the virtual zoom meetings taking place these days)

But the boss is worried that the employees which are participating the meeting are not going to take it seriously.

Any subset of employees can form a group and two people are said to be neighbours in the group if there is no other group participant
 sitting between them in clockwise direction. (Note: there can be employees sitting between them but they must not be part of the group.)

The boss knows that whenever there is any group of two or more people in the meeting, such that each pair of neighbouring people
 in the group is equidistant, then the group starts to play a game where they will be passing a paper ball to the next person in
  the group in clockwise direction and the game will be continued throughout the meeting without the boss getting noticed.

Now the employees are seated around the table with possibly some empty seats and the meeting is about to start. Can you help the
'' boss to decide whether the important meeting should be started or it is not the day for a serious discussion.

Note : The boss starts the meeting only if no such group can be formed else the group members dont stay attentive during the meeting
*/
int main() {
    ll i,j,k,l,n,t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        set<ll> st;
        for(i=2;i*i<=n;i++) {
            if(n%i==0){
                st.insert(i);
                st.insert(n/i);
            }
        }
        bool fl=true;
        for(auto f:st){
            if(f!=n){
            int cnt[f]={0};
            for(i=0;i<n;i++)
                if(s[i]=='#') cnt[i%f]++;
            for(i=0;i<f;i++){
                if(cnt[i]*f==n)
                {
                    fl=0;
                    break;
                }
            }
            if(!fl) break;
            }
        }
        if(fl)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
