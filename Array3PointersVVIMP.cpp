// INTERVIEWBIT BEST AND SHORTEST
int Solution::minimize(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
     int diff = INT_MAX;
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        int i, j, k;
        for(i = 0, j = 0, k = 0; i < a.size() && j < b.size() && k < c.size();) {
            minimum = min(a[i], min(b[j], c[k]));
            maximum = max(a[i], max(b[j], c[k]));
            diff = min(diff, maximum - minimum);
            if (diff == 0) break;
            if (a[i] == minimum) i++;
            else if (b[j] == minimum) j++;
            else k++;
        }
        return diff;
}











int binsearch(const vector<int> &v,int tar)
{
    int n = v.size();
    int i=0,j=n-1,m,ans=-1;
    while(i<=j)
    {
        m = i+(j-i)/2;
        if(v[m]<=tar)
        {
            ans = m;
            i=m+1;
        }
        else
        j=m-1;
    }
    return ans;
}
int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int l,r,i,j,k,n,m,p,mindiff=INT_MAX;
    n=A.size();
    m = B.size();
    p = C.size();
    for(i=0;i<n;i++)
    {
        l = binsearch(B,A[i]);
        r = binsearch(C,A[i]);
        if(l!=-1&&r!=-1)
        mindiff = min(mindiff,max(abs(A[i]-B[l]),max(abs(A[i]-C[r]),abs(B[l]-C[r]))));
    }
    for(i=0;i<m;i++)
    {
        l = binsearch(A,B[i]);
        r = binsearch(C,B[i]);
        if(l!=-1&&r!=-1)
        mindiff = min(mindiff,max(abs(B[i]-A[l]),max(abs(B[i]-C[r]),abs(A[l]-C[r]))));
    }
    for(i=0;i<p;i++)
    {
        l = binsearch(A,C[i]);
        r = binsearch(B,C[i]);
        if(l!=-1&&r!=-1)
        mindiff = min(mindiff,max(abs(C[i]-A[l]),max(abs(C[i]-B[r]),abs(A[l]-B[r]))));
    }
    return mindiff;
    
}
