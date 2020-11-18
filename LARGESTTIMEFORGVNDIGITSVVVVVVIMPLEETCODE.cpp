class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int i,j,k,l,ans=-1;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(j!=i)
                {
                    for(k=0;k<4;k++)
                    {
                        if(k!=i&&k!=j)
                        {
                            l=6-i-j-k;
                            int h = A[i]*10+A[j];
                            int m = A[k]*10+A[l];
                            if(h<24&&m<60)
                            {
                                ans =  max(ans,h*60+m);
                            }
                        }
                    }
                }
            }
        }
        string s="";
        if(ans>=0)
        {
            if(ans==0)
                return "00:00";
            s = ((ans>=60)?(to_string(ans/60)):"00")+":"+((ans%60==0)?"00":to_string(ans%60));
            if((ans/60)<10)
                s.insert(s.begin(),'0');
            if((ans%60)<10&&(ans%60)!=0)
                s.insert(s.begin()+3,'0');
            return s;
        }
        else
            return "";
        
    }
};