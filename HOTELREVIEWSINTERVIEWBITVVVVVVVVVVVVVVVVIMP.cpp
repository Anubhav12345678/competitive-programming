
/*
Given a set of reviews provided by the customers for different hotels and a string containing 
Good Words, you need to sort the reviews in descending order according to their Goodness Value
 (Higher goodness value first). We define the Goodness Value of a string as the number of Good Words in that string.

NOTE: Sorting should be stable. If review i and review j have the same Goodness Value then their original order would be preserved.

You are expected to use Trie in an Interview for such problems



*/



vector<int> Solution::solve(string A, vector<string> &B) {
    map<string,int> mp;
    int i =0,n = A.size();
    while(1){
        int j = i;
        while( j < n && A[j] != '_')++j;
        mp[A.substr(i,j-i)]++;
        i = j + 1;
        if(j == n)break;
    }
    vector<pair<int,int>> ans;
    // goodness values , for stability their order , string 
    n = B.size();
    for(int x =0;x<n;++x){
        string str = B[x];
        int i = 0,sz = str.size(),good = 0;
        while(1){
            int j = i;
            while( j < sz && str[j] != '_')++j;
            if(mp[str.substr(i,j-i)])good++;
            i = j + 1;
            if(j == sz)break;
        }
        ans.push_back({-good,x});
    }
    sort(ans.begin(),ans.end());
    vector<int> a;
    for(int i= 0;i<ans.size();++i)a.push_back(ans[i].second);
    return a;
    
}

