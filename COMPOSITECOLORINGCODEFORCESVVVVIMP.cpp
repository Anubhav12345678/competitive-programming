
/*
A positive integer is called composite if it can be represented as a product of two positive integers,
 both greater than 1. For example, the following numbers are composite: 6, 4, 120, 27. The following numbers 
 aren't: 1, 2, 3, 17, 97.

Alice is given a sequence of n composite numbers a1,a2,…,an.

She wants to choose an integer m≤11 and color each element one of m colors from 1 to m so that:

for each color from 1 to m there is at least one element of this color;
each element is colored and colored exactly one color;
the greatest common divisor of any two elements that are colored the same color is greater than 1, i.e.
 gcd(ai,aj)>1 for each pair i,j if these elements are colored the same color.
Note that equal elements can be colored different colors — you just have to choose one of m colors for
 each of the indices from 1 to n.

Alice showed already that if all ai≤1000 then she can always solve the task by choosing some m≤11.

Help Alice to find the required coloring. Note that you don't have to minimize or maximize the number of
 colors, you just have to find the solution with some m from 1 to 11.





*/




#include<bits/stdc++.h>
using namespace std;
 
int n,t;
vector<int> ans[1007];
int res[1007];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    auto f=[&](int u){
        for (int i=2;i<=u;++i){
            if (u%i==0) return i;
        }
    };
    cin>>t;
    while (t--){
        cin>>n;
        for (int i=1;i<=1000;++i) ans[i].clear();
        for (int i=1;i<=n;++i){
           int u;
           cin>>u; ans[f(u)].push_back(i);
        }
        int ret=0;
        for (int i=1;i<=1000;++i){
            if (ans[i].size()){
                ++ret;
                for (auto c:ans[i]){
                    res[c]=ret;
                }
            }
        }
        cout<<ret<<"\n";
        for (int i=1;i<=n;++i){
            cout<<res[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}