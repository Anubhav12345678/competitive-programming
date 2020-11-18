string Solution::convert(string A, int B) {
    if(B==1)
    return A;
    int n = A.size();
    string res = "";
    string arr[B];
    bool d;
    int row=0;
    for(int i=0;i<n;i++)
    {
        arr[row].push_back(A[i]);
        if(row==0)
        d = true;
        if(row==B-1)
        d = false;
        (d)?(row++):row--;
    }
    for(int i=0;i<B;i++)
    res+=arr[i];
    return res;
    
}
