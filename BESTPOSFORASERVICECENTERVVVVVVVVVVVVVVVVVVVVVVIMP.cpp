class Solution {
    /*
A delivery company wants to build a new service centre in a new city. The company knows the positions of
 all the customers in this city on a 2D-Map and wants to build the new centre in a position such that the
  sum of the euclidean distances to all customers is minimum.

Given an array positions where positions[i] = [xi, yi] is the position of the ith customer on the map, return
 the minimum sum of the euclidean distances to all customers.

In other words, you need to choose the position of the service centre [xcentre, ycentre] such that the following formula is minimized:


Answers within 10^-5 of the actual value will be accepted.



    */
public:
    double solve(double x1,double y1,double x2,double y2)
    {
        return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    }
    double getdis(double x,double y,vector<vector<int>>& pos)
    {
        double res=0.0;
        for(int i=0;i<(int)pos.size();i++)
        {
            res+=solve(x,y,(double)pos[i][0], (double)pos[i][1]);
        }
        return res;
    }
    double getMinDistSum(vector<vector<int>>& positions) {
        int i,j,k,l,n=positions.size();
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        double x=0.0,y=0.0,step=50.0;
        double res=getdis(x,y,positions);
        while(step>0.0000001)
        {
            bool f=false;
            for(i=0;i<4;i++)
            {
                double nx = x+step*dx[i];
                double ny = y+step*dy[i];
                double curdis = getdis(nx,ny,positions);
                if(curdis<res)
                {
                    res=curdis;
                    x=nx;
                    y=ny;
                    f=true;
                    break;
                }
            }
            if(!f)
                step/=2;
        }
        
        return res;
    }
};