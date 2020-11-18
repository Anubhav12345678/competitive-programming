#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
    int t; scanf("%d", &t);
    while(t--){
        string s;
        cin >> s;
        int left = 0, right = 0, max_length = 0, length = s.length(), i;
        for(i = 0; i < length; i++){
            if(s[i] == '(') left++;
            else right++;
            if(left == right) max_length = max(max_length, (left*2));
            else if(left < right) left = right = 0;
        }
        right = left = 0;
        for(i = length - 1; i > -1; i--){
            if(s[i] == ')') right++;
            else left++;
            if(right == left) max_length = max(max_length, (right* 2));
            else if(right < left) right = left = 0;
        }
        printf("%d\n", max_length);
    }
}