class Solution {
public:
    double max(double a,double b)
    {
        if(a>b)
            return a;
        return b;
    }
    double area(int x1,int y1,int x2,int y2,int x3,int y3)
    {
        int z = (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
        z  = abs(z);
        return (double)z*0.5;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int i,j,k,l,n=points.size();
        double ans=0.0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    ans = max(ans,area(points[i][0],points[i][1],points[j][0],points[j][1],points[k][0],points[k][1]));
                    // cout<<"i = "<<i<<"j  ="<<j<<" k= "<<k<<endl;
                    // cout<<"ans = "<<ans<<endl;
                }
            }
        }
        return ans;
    }
};