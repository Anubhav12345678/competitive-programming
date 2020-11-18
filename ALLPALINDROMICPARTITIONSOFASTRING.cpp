bool ispalin(string s,int st,int en)
{
    if(st>en)
    return false;
    if(st==en)
    return true;
    if(st<en)
    {
        int i=st,j=en;
        while(i<j)
        {
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
    }
    return true;
}
void helper(vector<vector<string>> &res,vector<string> &cur,int ind,string s)
{
    if(ind==s.size())
    {
        res.push_back(cur);
        return;
    }
    for(int j=ind;j<s.size();j++)
    {
        if(ispalin(s,ind,j))
        {
            cur.push_back(s.substr(ind,j-ind+1));
            helper(res,cur,j+1,s);
            cur.pop_back();
        }
    }
    return;
}
vector<vector<string> > Solution::partition(string A) {
    vector<vector<string>> res;
    vector<string> cur;
    helper(res,cur,0,A);
    sort(res.begin(),res.end());
    return res;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
