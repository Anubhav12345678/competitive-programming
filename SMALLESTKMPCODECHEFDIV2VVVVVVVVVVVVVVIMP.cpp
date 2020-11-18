#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define x first
#define y second    
#define mp make_pair
#define sz(a) ((int)(a.size()))
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;
const int INF = 1000 * 1000 * 1000;
const int MAX = 500000;
int cnt[256];
int cnt2[256];
/*

Chef has a string S. He also has another string P, called pattern. He wants to find the pattern in S, but
 that might be impossible. Therefore, he is willing to reorder the characters of S in such a way that P occurs 
 in the resulting string (an anagram of S) as a substring.

Since this problem was too hard for Chef, he decided to ask you, his genius friend, for help. Can you find the
 lexicographically smallest anagram of S that contains P as substring?

Note: A string B is a substring of a string A if B can be obtained from A by deleting several (possibly none or all) 
characters from the beginning and several (possibly none or all) characters from the end.

Input

*/
int main() {
    int T;
    cin >> T;
    while(T--)
    {
        memset(cnt, 0 , sizeof cnt);
        memset(cnt2 , 0 , sizeof cnt2);
        string S , P;
        cin >> S >> P;
        int ptrP = 0;
        for(auto x : S)
            cnt[x]++;
        for(auto x : P)
            cnt2[x]++;
        int inc = 0;
        for(int i = 0; i < sz(P) - 1; i++)
        {
            if(P[i] < P[i + 1])
                inc = 1;
            if(P[i] > P[i + 1])
                inc = -1;
            if(inc) break;
        }
        char to = P[0] - (inc != 1);
        
        for(char i = 'a'; i <= to; i++)
            for(int x = 0; x < cnt[i] - cnt2[i]; x++)
                cout << i;
        cout << P;
        for(char i = to + 1; i <= 'z'; i++)
            for(int x = 0; x < cnt[i] - cnt2[i]; x++)
                cout << i;
        cout << endl;
    }
} 