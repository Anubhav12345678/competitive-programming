int Solution::bulbs(vector<int> &A) {
    int i,j,k,l,n=A.size();
    k=0;
    int ans=0;
    for(i=0;i<n;i++)
    {
        if((A[i]+k)%2==0)
        {
            k++;
            ans++;
        }
    }
    return ans;
}
/*

N light bulbs are connected by a wire.

Each bulb has a switch associated with it, however due to faulty wiring, a switch also changes the state of all the bulbs to the right of current bulb.

Given an initial state of all bulbs, find the minimum number of switches you have to press to turn on all the bulbs.

You can press the same switch multiple times.

Note : 0 represents the bulb is off and 1 represents the bulb is on.



Input Format:

The first and the only argument contains an integer array A, of size N.


*/