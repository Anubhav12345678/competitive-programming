
/*

Given an integer array of digits, return the largest multiple of three that can be formed by concatenating some 
of the given digits in any order.

Since the answer may not fit in an integer data type, return the answer as a string.

If there is no answer return an empty string.




*/


///MEEEEEEE
class Solution {
public:
    string rem1(vector<int> res,int ind1,int ind2=-1)
    {
        string r="";
        for(int i=0;i<res.size();i++)
        {
            if(i!=ind1&&i!=ind2)
                r+=to_string(res[i]);
        }
        return r;
    }
    string largestMultipleOfThree(vector<int>& dig) {
        int i,j,k,l,n=dig.size();
        sort(dig.begin(),dig.end(),greater<>());
        int sum = accumulate(dig.begin(),dig.end(),0);
        if(sum==0)
            return "0";
        if(sum%3==0)
        {
            string res="";
            for(i=0;i<n;i++)
                res+=to_string(dig[i]);
            return res;
        }
        if(sum%3==1)
        {
            int ind1=-1,ind2=-1,ind3=-1;
            for(i=n-1;i>=0;i--)
            {
                if(dig[i]%3==1)
                    return rem1(dig,i);
                else if(dig[i]%3==2)
                {
                    if(ind1==-1)
                        ind1=i;
                    else if(ind2==-1)
                        ind2=i;
                }
            }
            if(ind1!=-1&&ind2!=-1)
                return rem1(dig,ind1,ind2);
        }
        
            int ind1=-1,ind2=-1,ind3=-1;
            for(i=n-1;i>=0;i--)
            {
                if(dig[i]%3==2)
                    return rem1(dig,i);
                else if(dig[i]%3==1)
                {
                    if(ind1==-1)
                        ind1=i;
                    else if(ind2==-1)
                        ind2=i;
                }
            }
            if(ind1!=-1&&ind2!=-1)
                return rem1(dig,ind1,ind2);
        return "";
    }
};



class Solution {
public:
    void pop(queue<int> q0,queue<int> q1,queue<int> q2,int *top,vector<int> &v)
    {
        while(!q0.empty())
        {
            v[(*top)++]=q0.front();
            q0.pop();
        }
        while(!q1.empty())
        {
            v[(*top)++]=q1.front();
            q1.pop();
        }
        while(!q2.empty())
        {
            v[(*top)++]=q2.front();
            q2.pop();
        }
    }
    string largestMultipleOfThree(vector<int>& d) {
        int i,j,k,l,n=d.size();
        if(n==1)
        {
            if(d[0]%3!=0)
                return "";
            return to_string(d[0]);
        }
        sort(d.begin(),d.end());
        if(d[n-1]==0)
            return "0";
        int sum = accumulate(d.begin(),d.end(),0);
        // if(sum%3==0)
        // {
        //     string res="";
        //     for(i=0;i<n;i++)
        //         res+=to_string(d[i]);
        //     return res;
        // }
        vector<pair<int,int>> v1,v2;
        queue<int> q0,q1,q2;
        for(i=0;i<n;i++)
        {
            if(d[i]%3==0)
                q0.push(d[i]);
            else if(d[i]%3==1)
                q1.push(d[i]);
            else
                q2.push(d[i]);
        }
        if(sum%3==0)
        {
            string res="";
            for(i=n-1;i>=0;i--)
                res+=to_string(d[i]);
            return res;
        }
         if(sum%3==1)
         {
             if(!q1.empty())
                 q1.pop();
             else
             {
                 if(!q2.empty())
                     q2.pop();
                 else
                     return "";
                 if(!q2.empty())
                     q2.pop();
                 else
                     return "";
             }
         }
        if(sum%3==2)
         {
             if(!q2.empty())
                 q2.pop();
             else
             {
                 if(!q1.empty())
                     q1.pop();
                 else
                     return "";
                 if(!q1.empty())
                     q1.pop();
                 else
                     return "";
             }
         }
        vector<int> v(n);
        int top=0;
        pop(q0,q1,q2,&top,v);
        string res="";
        sort(v.begin(),v.begin()+top,greater<>());
        for(i=0;i<top;i++)
            res+=to_string(v[i]);
        return res;
        
    }
};