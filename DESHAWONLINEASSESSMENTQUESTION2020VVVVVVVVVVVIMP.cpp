O(n) time ,O(n) space

int maxDiff(vector<int>arr) {
        int n = arr.size();
        int alice[n];
        int bob[n];
        alice[0] = arr[0];
        bob[0] = 0;
        for(int i=1;i<arr.size();i++)
        {
            alice[i] = max(alice[i-1],bob[i-1]+arr[i]);
            bob[i] = max(bob[i-1],alice[i-1]-arr[i]);
        }
        return max(alice[n-1],bob[n-1]);
    }
O(n) time ,O(1) space

int maxDiff(vector<int>arr) 
{
    int alice = arr[0];     
    int bob = 0;            
    for(int i=1;i<arr.size();i++)
    {
        int a = alice;
        int b = bob;
        alice = max(alice,b+arr[i]);
        bob =   max(bob,a-arr[i]);
    }
    return max(alice,bob);
}