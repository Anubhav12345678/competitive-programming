int fact(int n)
{
    if(n>12)
    return INT_MAX;
    return (n<=0)?1:(n*fact(n-1));
}
string generate(int k,vector<int> ar)
{
    int n=ar.size();
    if(n==0)
    return "";
    if(k>fact(n))
    return to_string(INT_MAX);
    int f=fact(n-1);
    int pos = k/f;
    k%=f;
    string ch=to_string(ar[pos]);
    ar.erase(ar.begin()+pos);
    return ch+generate(k,ar);
}
string Solution::getPermutation(int A, int B) {
    vector<int> ar;
    for(int i=1;i<=A;i++)
    ar.push_back(i);
    return generate(B-1,ar);
    
}
