class Solution {
public:
    string helper(int x1,int y1,int x2,int y2)
    {
        int a = x1*5+y1;
        int b = x2*5+y2;
        if(a==b)
            return "";
        if(a==25)
            return "U"+helper(x1-1,y1,x2,y2);
        if(b==25)
            return helper(x1,y1,4,0)+"D";
        string ans="";
        if(x2>x1)
            ans+=string(x2-x1,'D');
        else if(x1>x2)
            ans+=string(x1-x2,'U');
        if(y2>y1)
            ans+=string(y2-y1,'R');
        else if(y1>y2)
            ans+=string(y1-y2,'L');
        return ans;
            
    }
    string alphabetBoardPath(string target) {
        int idx=0,i,j,k,l;
        int n = target.size();
        vector<int> x(26),y(26);
        string ans="";
        for(i=0;i<6&&idx<26;i++)
        {
            for(j=0;j<5&&idx<26;j++)
            {
                x[idx]=i;
                y[idx]=j;
                idx++;
            }
        }
        int curx=0,cury=0;
        for(i=0;i<n;i++)
        {
            int xx = x[target[i]-'a'];
            int yy = y[target[i]-'a'];
            if(curx!=xx||cury!=yy)
            {
                ans+=helper(curx,cury,xx,yy);
            }
            ans+="!";
            curx=xx;
            cury=yy;
        }
        return ans;
        
    }
};