vector<int> solve(vector<int>& nums) {
    int td = 0;
    int n = nums.size();
    int br = 0;
    for(int i=0;i<n;i++)
    {
        if(nums[i])
        {
          td+=i;
          br++;
        }
    }
    // cout<<" td =  "<<td<<" br = "<<br<<endl;
    int bl=0;
    vector<int> res(n);
    for(int i=0;i<n;i++)
    {
        if(nums[i])
        {
            bl++;
            br--;
        }
        res[i]=td;
        td-=br-bl;
    }
    return res;
}
/*

You are given a list of integers nums containing 0s and 1s where a 0 means the cell is empty and 1 means there's a ball there.

Return a new list of integers A of the same length where A[i] is set to the total distance required to move all the balls to A[i]. The distance to move a ball in index j to index i is defined to be abs(j - i).

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input

nums = [1, 1, 0, 1]
Output

[4, 3, 4, 5]


*/