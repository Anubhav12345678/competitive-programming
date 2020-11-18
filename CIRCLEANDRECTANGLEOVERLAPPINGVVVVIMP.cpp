
/*
Given a circle represented as (radius, x_center, y_center) and an axis-aligned rectangle represented as 
(x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the
 coordinates of the top-right corner of the rectangle.

Return True if the circle and rectangle are overlapped otherwise return False.

In other words, check if there are any point (xi, yi) such that belongs to the circle and the rectangle at the same time.



*/




class Solution {
public:
    int dis(int x1,int y1,int x2,int y2)
    {
        return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    }
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if(x1<=x_center&&x_center<=x2&&y1<=y_center&&y_center<=y2)
            return 1;
        for(int x=x1;x<=x2;x++)
        {
            if(dis(x,y1,x_center,y_center)<=radius*radius)
                return 1;
        }
        for(int x=x1;x<=x2;x++)
        {
            if(dis(x,y2,x_center,y_center)<=radius*radius)
                return 1;
        }
        for(int y=y1;y<=y2;y++)
        {
            if(dis(x1,y,x_center,y_center)<=radius*radius)
                return 1;
        }
        for(int y=y1;y<=y2;y++)
        {
            if(dis(x2,y,x_center,y_center)<=radius*radius)
                return 1;
        }
        return 0;
    }
};