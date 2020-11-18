string Solution::solve(string A, int B) {
    int n=A.length();
int i=0;
string ans;
while(i<n)
{
    int count=1;
    while(i<n-1 and A[i]==A[i+1])
    {
        count++;
        i++;
    }
    if(count!=B)
    {
        while(count--)
        {
            ans+=A[i];
        }
    }
    i++;
}
return ans;
    
}
//Given a string A and integer B, remove all consecutive same characters that have length exactly B.