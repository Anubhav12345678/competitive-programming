#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    cin >> a;
    map<char,int> m;
    for(char i: a)m[i]++;
    string ans = "";
    char c = 'z'+1;
    for(auto &i: m){
        ans+=string(i.second/2,i.first);
        i.second&=1;
        if(i.second)c = min(i.first,c);
    }
    cout << ans ;
    if(c != 'z'+1)cout << c;
    reverse(ans.begin(),ans.end());
    cout << ans ;
    return 0;
}
/*
Ayush loves strings, especially palindromes. He was given a string, he wishes to know the longest palindrome he can make with the characters of the string, but he wants that string to be lexicographically smallest string.

For example, if s = "abcdab", few of the possible pallindromes are a,b,aba,bacab,abcba Out of longest palindromes, we need to select lexicographically smallest one, thus answer is "abcba"

Input Format

A single string of lowercase characters only

*/