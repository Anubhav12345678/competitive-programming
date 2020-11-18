#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

/*
Ram and his friends decide to play treasure hunt, but everyone
 thought it was boring. Ram thinks treasure hunt is amazing, so he comes up with an interesting way of making teams:

All participants should stand in a queue, the order of which is determined by Ram.
Every participant has 2 choices, they can either make their own team, or be a part of someone else's team.
To make a team, a participant can only consider the participants to their back in the queue.
Consequetively, each team's participants should be standing in non-decreasing order of heights in the original queue.
The game has not started yet and Ram is busy making clues for the treasure hunt, so he asked everyone
 to figure out the maximum size of the team they can make. Can you solve this problem for them?
*/
vector<int> lis(vector<int> &arr) {
    int n = arr.size();
    multiset<int> s;
    vector<int> ans(n);
    for (int i = 0; i <= n-1; ++i) {
        s.insert(arr[i]);
        auto it = s.upper_bound(arr[i]);
        if (it != s.end()) {
            s.erase(it);
        }

        ans[i] = s.size();
    }

    return ans;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> ans = lis(arr);
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    
    return 0;
}
