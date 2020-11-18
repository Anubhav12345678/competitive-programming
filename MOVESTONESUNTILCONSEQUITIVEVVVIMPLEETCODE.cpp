class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> p;
        p.push_back(a);
        p.push_back(b);
        p.push_back(c);
        int i,j,k,l;
        sort(p.begin(),p.end());
        int cnt1=0;
        int cnt2=0;
        if(p[0]==p[1]-1&&p[1]==p[2]-1)
            return {0,0};
        cnt2 = (p[1]-p[0]-1)+(p[2]-p[1]-1);
        // cnt1 = ((p[1]==p[0]+1)?0:1)+((p[1]==p[2]-1)?0:1);
        if(p[0]==p[1]-1)
            cnt1=1;
        else if(p[1]==p[2]-1)
            cnt1=1;
        else if((p[1]-p[0]==2))
            cnt1=1;
        else if((p[2]-p[1]==2))
            cnt1=1;
        else
        cnt1 = 2;
        return {cnt1,cnt2};
        
    }
};