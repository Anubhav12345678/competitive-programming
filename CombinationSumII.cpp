void generate(vector<int> &a,int sum,vector<int> &tmp,vector<vector<int>> &res,int ind)
{
    if(sum<0)
    return;
    if(ind>=a.size()&&sum!=0)
    return;
    if(sum==0)
    {
        sort(tmp.begin(),tmp.end());
        if(find(res.begin(),res.end(),tmp)==res.end())
        res.push_back(tmp);
        return;
    }
    for(int i=ind;i<a.size();i++)
    {
        tmp.push_back(a[i]);
        generate(a,sum-a[i],tmp,res,i+1);
        tmp.pop_back();
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<int> tmp;
    vector<vector<int>> res;
    int s=B;
    sort(A.begin(),A.end());
    generate(A,s,tmp,res,0);
    sort(res.begin(),res.end());
    return res;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
