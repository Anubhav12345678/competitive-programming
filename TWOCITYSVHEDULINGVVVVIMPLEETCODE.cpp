class Solution {
public:
    static bool comp(vector<int> a,vector<int> b)
    {
        return abs(a[0]-a[1])>abs(b[0]-b[1]);// this is imp as phle hm simple comparison krke add kr le shuru valo ko phir aage 
        //chlte hue unme zada diff rhega nhi
    }
    int twoCitySchedCost(vector<vector<int>>& c) {
        int i,j=0,k=0,l,n=c.size();
        if(n==0)
            return 0;
        sort(c.begin(),c.end(),comp);
        for(i=0;i<n;i++)
            cout<<c[i][0]<<" "<<c[i][1]<<endl;
        int res=0;
        for(i=0;i<n;i++)
        {
            if(j<n/2&&k<n/2)
            {
                if(c[i][0]<=c[i][1])
                {
                    res+=c[i][0];
                    j++;
                }
                else
                {
                    res+=c[i][1];
                    k++;
                }
            }
            else if(j==n/2)
            {
                res+=c[i][1];
                k++;
            }
            else
            {
                res+=c[i][0];
                j++;
            }
                
        }
        return res;
        
    }
};