/*
There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.

We need to find bridges with minimal cost such that all islands are connected.

It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.

Input Format:

The first argument contains an integer, A, representing the number of islands.
The second argument contains an 2-d integer matrix, B, of size M x 3:
    => Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].
*/
static bool comp(vector<int> a,vector<int> b)
{
    return a[2]<b[2];
}
int find(int par[],int i)
{
    if(par[i]==-1)
    return i;
    return find(par,par[i]);
}
void uni(int par[],int up,int vp)
{
   int xp = find(par,up);
   int yp = find(par,vp);
    par[xp]=yp;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    int n = B.size();
    sort(B.begin(),B.end(),comp);
    int par[A];
    memset(par,-1,sizeof(par));
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int xp = find(par,B[i][0]-1);
        int yp = find(par,B[i][1]-1);
        if(xp!=yp)
        {
            uni(par,xp,yp);
            ans+=B[i][2];
        }
    }
    return ans;
    
    
}
