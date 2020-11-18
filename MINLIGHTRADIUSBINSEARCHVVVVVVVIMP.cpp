int need(vector<int> &v,double m)
{
    int res=0;
    for(int i=0;i<v.size();)
    {
        res++;
        double upto = v[i]+2*m;
        int j=i+1;
        while(j<v.size()&&v[j]<=upto) j++;
        i=j;
    }
    return res;
}

double solve(vector<int>& nums) {
    int i,j,k,l,n=nums.size();
    sort(nums.begin(),nums.end());
    double lhs=0,rhs=nums[n-1]-nums[0];
    for(int q=0;q<40;q++)
    {
         double m = (lhs+rhs)/2;
         if(need(nums,m)<=3) rhs=m;
         else
         lhs=m;
    }
    return rhs;
}
/*

You are given a list of integers nums representing coordinates of houses on a 1-dimensional line. You have 3 street lights that you can put anywhere on the coordinate line and a light at coordinate x lights up houses in [x - r, x + r], inclusive. Return the smallest r required such that we can place the 3 lights and all the houses are lit up.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input

nums = [3, 4, 5, 6]
Output

0.5

*/