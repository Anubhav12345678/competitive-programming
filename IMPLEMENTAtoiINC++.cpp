int Solution::atoi(const string A) {
    int i=0,j,k,n;
    n = A.size();
    while(i<n&&A[i]==' ')
    i++;
    if(i==n)
    return 0;
    long long int num=0,sign=1;
    if(A[i]=='+'||A[i]=='-')
        {
            if(A[i]=='-')
            sign=-1;
            i++;
            // continue;
        }
    while(A[i]>='0'&&A[i]<='9')
    {
        if((num*10+(A[i]-'0'))>INT_MAX)
        {
            if(sign<0)
            return INT_MIN;
            return INT_MAX;
        }
        num = num*10+(A[i]-'0');
        if(num>INT_MAX||num<INT_MIN)
        {
            if(num>0)
            return INT_MAX;
            else if(num<0)
            return INT_MIN;
        }
        i++;
    }
    if(num>INT_MAX||num<INT_MIN)
        {
            if(num>0)
            return INT_MAX;
            else if(num<0)
            return INT_MIN;
        }
    return num*sign;
    
}



//meeeeeee
#define ll long long int
class Solution {
public:
    int myAtoi(string str) {
        long long int res=0LL;
        ll i,j,k,l,n=str.size();
        if(n==0)
            return 0;
        i=0;
        while(i<n&&str[i]==' ')
            i++;
        if(i==n)
            return 0;
        if((str[i]>='0'&&str[i]<='9')||str[i]=='+'||str[i]=='-')
        {
            ll sign=1LL;
           if(str[i]=='+'||str[i]=='-')
           {
               if(str[i]=='-')
                   sign*=-1;
               i++;
           }
            if(i<n)
            {
                res=0LL;
                while(i<n&&str[i]!=' '&&str[i]>='0'&&str[i]<='9')
                {
                    res = res*10+(ll)(str[i]-'0');
                    ll tmp = res*sign;
                    if(tmp>=INT_MAX)
                        return INT_MAX;
                    else if(tmp<=INT_MIN)
                        return INT_MIN;
                    i++;
                }
                res*=sign;
                if(res>=INT_MAX)
                    return INT_MAX;
                if(res<=INT_MIN)
                    return INT_MIN;
                return res;
            }
            return 0LL;
        }
        
        
        
        return 0;
        
    }
};