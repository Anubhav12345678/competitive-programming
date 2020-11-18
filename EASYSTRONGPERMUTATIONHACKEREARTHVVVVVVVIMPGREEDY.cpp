#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p = 1e9+7;
const int MAXN = 1e5+5;
ll nums[MAXN], n, sum;
int main() {
    cin >> n; for (int i = 0; i < n; ++i)
        cin >> nums[i];
    sort(nums, nums+n);
    for (int i = 0; i < n/2; ++i)
        sum -= 2*nums[i], sum += 2*nums[n-1-i];
    cout << sum << "\n";
}
/*

Kevin has a sequence of integers a1, a2, ..., an. Define the strength of the sequence to be

|a1 - a2| + |a2 - a3| + ... + |an-1 - an| + |an - a1|.

Kevin wants to make his sequence stronger, so he reorders his sequence into a new sequence b1, b2, ..., bn. He wants
 this new sequence to be as strong as possible. What is the largest possible strength of the resulting sequence?


*/