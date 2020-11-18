// MEEEEELEETCODE
class Solution {
public:
    vector<int> l(vector<int> &v)
    {
        stack<int> st;
        int i,j,k,l,n=v.size();
        vector<int> res(n);
        for(i=0;i<n;i++)
        {
            while(!st.empty()&&v[i]<=v[st.top()])
                st.pop();
            if(st.empty())
                res[i]=-1;
            else
                res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> r(vector<int> &v)
    {
        stack<int> st;
        int i,j,k,l,n=v.size();
        vector<int> res(n);
        for(i=n-1;i>=0;i--)
        {
            while(!st.empty()&&v[i]<=v[st.top()])
                st.pop();
            if(st.empty())
                res[i]=n;
            else
                res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    int maxhist(vector<int> &v)
    {
        int i,j,k,n=v.size();
        int ans=0;
        vector<int> left = l(v);
        // for(i=0;i<n;i++)
        vector<int> right  =r(v);
        // for(i=0;i<n;i++)
            // cout<<"left["<<i<<"] = "<<left[i]<<" right["<<i<<"] = "<<right[i]<<endl;
        for(i=0;i<n;i++)
        {
            ans = max(ans,v[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int i,j,k,l,n=matrix.size();
        if(n==0)
            return 0;
        int m = matrix[0].size();
        if(m==0)
            return 0;
        vector<vector<int>> v(n,vector<int>(m));
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                v[i][j] = matrix[i][j]-'0';
        int ans=maxhist(v[0]);
        // cout<<"ans = "<<ans<<endl;
        for(i=1;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(v[i][j])v[i][j]+=v[i-1][j];
                // ans = max(ans,maxhist(v[i]));
            }
            ans = max(ans,maxhist(v[i]));
        }
        return ans;
    }
};









class Solution {
public:
    int maxhist(vector<int> &v)
    {
        int n = v.size();
        stack<int> st;
        int area=0,i=0,maxarea=0;
        int topval;
        while(i<n)
        {
            if(st.empty()||v[st.top()]<=v[i])
                st.push(i++);
            else
            {
                topval = v[st.top()];
                st.pop();
                area = (topval)*i;
                if(!st.empty())
                    area = (topval)*(i-st.top()-1);
                maxarea = max(area,maxarea);
            }
        }
        while(!st.empty())
        {
            topval = v[st.top()];
                st.pop();
                area = (topval)*i;
                if(!st.empty())
                    area = (topval)*(i-st.top()-1);
                maxarea = max(area,maxarea);
        }
        return  maxarea;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m==0)
            return 0;
        int n = matrix[0].size();
        if(n==0)
            return 0;
        int i,j,k,l;
        vector<vector<int>> v(m);
        for(i=0;i<m;i++)
            v[i] = vector<int>(n);
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                v[i][j] = matrix[i][j]-'0';
        int res = maxhist(v[0]);
        for(i=1;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(v[i][j])v[i][j]+=v[i-1][j];
                res = max(res,maxhist(v[i]));
            }
        }
        
        return res;
    }
};