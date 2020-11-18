
/*


In a deck of cards, each card has an integer written on it.

Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or
 more groups of cards, where:

Each group has exactly X cards.
All the cards in each group have the same integer.


*/



class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int i,j,k,l;
        int n = deck.size();
        if(n==1)
            return 0;
        map<int,int> mp;
            for(i=0;i<deck.size();i++)
                mp[deck[i]]++;
        for(auto it = mp.begin();it!=mp.end();it++)
            cout<<it->first<<" "<<it->second<<endl;
        int x = mp.size();
        if(n>=2&&x==1)
            return 1;
            cout<<"dfgdfgfdg";
            int p = n/x;
            cout<<p<<endl;
        int q = 0;
            // auto it=mp.begin();
        int mini=INT_MAX;
        for(auto it=mp.begin();it!=mp.end();it++)
            q = __gcd(q,it->second);
        if(q==1)
            return 0;
        auto it=mp.begin();
        for(;it!=mp.end();it++)
            it->second%=q;
        it=mp.begin();
            for(;it!=mp.end();it++)
                if(it->second!=0)
                    break;
            if(it==mp.end())
                return 1;
        return 0;
        
    }
};