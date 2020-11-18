int Solution::seats(string A) {
    vector<int>v;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='x') v.push_back(i);
    }
    int n=v.size();
    int k=1,mid=n/2;
    int ans=0;
    int mod=10000003;
    for(int i=mid-1;i>=0;i--)
    {
        ans = (ans+(v[mid]-v[i]-k))%mod;
        k++;
    }
    k=1;
    for(int i=mid+1;i<n;i++)
    {
        ans = (ans+v[i]-(v[mid]+k))%mod;
        k++;
    }
    return ans%mod;
    
}
/*

There is a row of seats. Assume that it contains N seats adjacent to each other. There is a group of people who are already seated in that row randomly. i.e. some are sitting together & some are scattered.

An occupied seat is marked with a character 'x' and an unoccupied seat is marked with a dot ('.')

Now your target is to make the whole group sit together i.e. next to each other, without having any vacant seat between them in such a way that the total number of hops or jumps to move them should be minimum.

Return minimum value % MOD where MOD = 10000003

*/