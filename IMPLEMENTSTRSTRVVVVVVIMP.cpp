int Solution::strStr(const string A, const string B) {
   int n1 = A.size();
int n2 = B.size();
int i=0, j=0, k;

if(n1==0 || n2==0 || n2>n1)
    return -1;
    
for(; i<=n1-n2; i++) {
    k=i;
    j=0;
    while(A[k] == B[j]) {
        k++;
        j++;
        if(j==n2)
            return i;
    }
}
return -1;
}
