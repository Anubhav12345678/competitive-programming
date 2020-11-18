class Solution {
public:
    multiset<int> solve(int n){
        multiset<int> s;
        while(n>0){
            s.insert(n%10);
            n/=10;
        }
        
        return s;
    }
    bool reorderedPowerOf2(int N) {
        if(N==0||N==1) return N;
        long long int cc=0,power2=8,i,j,k,l,n;
        multiset<int> s;
        while(N>0){
            s.insert(N%10);
            N/=10;
            cc++;
        }
        
        for(i=4;i<=4*cc;i++) // dig in binary<= 4*digitsindecomal
        {
            power2*=2;
            multiset<int> cnt = solve(power2);
            if(cnt==s) return true;
        }
        
        return false;
    }
};
/*
Starting with a positive integer N, we reorder the digits in any order (including the original order) such that 
the leading digit is not zero.

Return true if and only if we can do this in a way such that the resulting number is a power of 2.

*/