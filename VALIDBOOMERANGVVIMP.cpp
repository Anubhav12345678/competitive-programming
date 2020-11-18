
/*

A boomerang is a set of 3 points that are all distinct and not in a straight line.

Given a list of three points in the plane, return whether these points are a boomerang.



*/




class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int i,j,k,l;
        int x1 = points[0][0];
        int y1 = points[0][1];
        int x2 = points[1][0];
        int y2 = points[1][1];
        int x3 = points[2][0];
        int y3 = points[2][1];
        if(x1==x2&&y1==y2)
            return 0;
        if(x1==x3&&y1==y3)
            return 0;
        if(x3==x2&&y3==y2)
            return 0;
        int dff1 = x1-x2;
        int dff2 = y1-y2;
        int g1 = __gcd(dff1,dff2);
        map<pair<int,int>,int> mp;
        dff1/=g1;
        dff2/=g1;
        mp[{dff1,dff2}]++;
        dff1 = x2-x3;
        dff2 = y2-y3;
        int g2 = __gcd(dff1,dff2);
        // map<pair<int,int>,int> mp;
        dff1/=g2;
        dff2/=g2;
        mp[{dff1,dff2}]++;
        return mp.size()==2;
    }
};