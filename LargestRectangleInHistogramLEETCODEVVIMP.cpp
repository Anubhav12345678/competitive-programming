vector<int> l(vector<int> &v)
{
    int i,j,k,l,n=v.size();
    vector<int> left(n);
    stack<int> st;
    for(i=0;i<n;i++)
    {
        while(!st.empty()&&v[i]<=v[st.top()])
        st.pop();
        if(st.empty())
        left[i]=-1;
        else
        left[i]=st.top();
        st.push(i);
    }
    return left;
}
vector<int> r(vector<int> &v)
{
    int i,j,k,l,n=v.size();
    vector<int> right(n);
    stack<int> st;
    for(i=n-1;i>=0;i--)
    {
        while(!st.empty()&&v[i]<=v[st.top()])
        st.pop();
        if(st.empty())
        right[i]=n;
        else
        right[i]=st.top();
        st.push(i);
    }
    return right;
}


int Solution::largestRectangleArea(vector<int> &A) {
    vector<int > left = l(A);
    vector<int> right = r(A);
    int ans=0,n=A.size();
    if(n==1)
    return A[0];
    for(int i=0;i<n;i++)
    {
        
        ans = max(ans,A[i]*(right[i]-left[i]-1));
    }
    return ans;
}
