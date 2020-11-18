class Solution {
public:
    map<int,string> mp;
    void fill()
    {
        mp.insert(make_pair(0,"Zero"));
        mp.insert(make_pair(1,"One"));
        mp.insert(make_pair(2,"Two"));
        mp.insert(make_pair(3,"Three"));
        mp.insert(make_pair(4,"Four"));
        mp.insert(make_pair(5,"Five"));
        mp.insert(make_pair(6,"Six"));
        mp.insert(make_pair(7,"Seven"));
        mp.insert(make_pair(8,"Eight"));
        mp.insert(make_pair(9,"Nine"));
        mp.insert(make_pair(10,"Ten"));
        mp.insert(make_pair(11,"Eleven"));
        mp.insert(make_pair(12,"Twelve"));
        mp.insert(make_pair(13,"Thirteen"));
        mp.insert(make_pair(14,"Fourteen"));
        mp.insert(make_pair(15,"Fifteen"));
        mp.insert(make_pair(16,"Sixteen"));
        mp.insert(make_pair(17,"Seventeen"));
        mp.insert(make_pair(18,"Eighteen"));
        mp.insert(make_pair(19,"Nineteen"));
        mp.insert(make_pair(20,"Twenty"));
        mp.insert(make_pair(30,"Thirty"));
        mp.insert(make_pair(40,"Forty"));
        mp.insert(make_pair(50,"Fifty"));
        mp.insert(make_pair(60,"Sixty"));
        mp.insert(make_pair(70,"Seventy"));
        mp.insert(make_pair(80,"Eighty"));
        mp.insert(make_pair(90,"Ninety"));
    }
    
    string convert(int n)
    {
        string st="";
        if(n>=100)
        {
            int nh = n/100;
            st+=" "+mp[nh]+" Hundred";
            n=n%100;
        }
        if(n>0)
        {
            if(n>0&&n<=20)
                st+=" "+mp[n];
            else
            {
                int nt = n/10;
                st+=" "+mp[nt*10];
                nt = n%10;
                if(nt>0)
                    st+=" "+mp[nt];
            }
        }
        return st;
    }
    string numberToWords(int num) {
        fill();
        string st="";
        if(num==0)
            return mp[num];
        if(num>=1000000000)
        {
            st+=convert(num/1000000000)+" Billion";
            num%=1000000000;
        }
        if(num>=1000000)
        {
            st+=convert(num/1000000)+" Million";
            num%=1000000;
        }
        if(num>=1000)
        {
            st+=convert(num/1000)+" Thousand";
            num%=1000;
        }
        if(num>=0)
        {
            st+=convert(num);
            // num%=1000000;
        }
        st.erase(st.begin());
        return st;
    }
    
    
    
};