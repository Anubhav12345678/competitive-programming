int Solution::diffPossible(vector<int> &a, int k) {
    int i=0,j=1;
    while(i<a.size() && j<a.size())
    {
        if(i!=j && a[j]-a[i]==k)
        {
            return 1;
        }
        else if(a[j]-a[i]<k)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return 0;
}
