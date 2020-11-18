struct Transaction
{
    int amt,time;
    string name,city;
    Transaction(string name="",int time=0,int amt=0,string city=""): name(name), time(time), amt(amt), city(city) {} 
};
class Solution {
public:
    struct Transaction parse(string s)
    {
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]==',')
                s[i]=' ';
        }
        stringstream sin(s);
        string a,d;
        int b,c;
        sin>>a>>b>>c>>d;
        return Transaction(a,b,c,d);
    }
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<struct Transaction> a;
        int i,j,k,l;
        for(i=0;i<n;i++)
            a.push_back(parse(transactions[i]));
        vector<string> res;
        for(i=0;i<n;i++)
        {
            if(a[i].amt>1000)
            {
                res.push_back(transactions[i]);
                continue;
            }
            else
            {
                for(j=0;j<n;j++)
                {
                    if(i!=j)
                    {
                        if(a[i].name==a[j].name&&abs(a[i].time-a[j].time)<=60&&a[i].city!=a[j].city)
                        {
                            res.push_back(transactions[i]);
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
};