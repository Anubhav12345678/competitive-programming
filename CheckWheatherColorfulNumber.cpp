/*
 A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
*/
int Solution::colorful(int A) {
    if(A<10)
    return 1;
    string s = to_string(A);
    int i,j,k,n=s.length();
    map<long long int,int> m;
    for(i=0;i<n;i++)
    {
        long long int mul=1;
        for(j=i;j<n;j++)
        {
            mul*=(s[j]-'0');
            if(m.find(mul)!=m.end())return 0;
            m.insert(make_pair(mul,1));
        }
    }
    return 1;
}
