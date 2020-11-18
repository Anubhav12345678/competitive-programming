class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0)
            return "0";
        bool f = (numerator>0&&denominator<0)||(numerator<0&&denominator>0);
        long long int n = abs((long long int)numerator);
        long long int d  = abs((long long int)denominator);
        long long int rem = n%d;
        long long int r = n/d;
        string s="";
        if(f)
            s="-";
        s+=to_string(r);
        if(rem==0)
            return s;
        map<int,int> m;
        s.append(".");
        while(rem!=0)
        {
             n = rem*10;
            if(m.find(n)!=m.end())
            {
              int p = m[n];
                s = s.substr(0,p)+'('+s.substr(p)+')';
              break;  
            }
            m[n] = s.size();
            r=n/d;
            rem=n%d;
            s.push_back(r+'0');
        }
        return s;
    }
};