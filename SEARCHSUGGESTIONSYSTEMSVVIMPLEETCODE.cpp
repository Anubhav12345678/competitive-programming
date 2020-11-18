class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& pr, string sw) {
        sort(pr.begin(),pr.end());
        int i,j,k,n,m;
        vector<vector<string > > res;
        string cur="";
        for(char c:sw){
            cur+=c;
            auto it = lower_bound(pr.begin(),pr.end(),cur);
            // if(it!=pr.end()){
                vector<string> tmp;
                for(i=0;i<3&&it+i!=pr.end();i++)
                {
                    string &s = *(it+i);
                    if(s.find(cur)) break;
                    tmp.push_back(s);
                }
                res.push_back(tmp);
                tmp.clear();
            // }
        }
        return res;
    }
};
/*
Given an array of strings products and a string searchWord. We want to design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with the searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return list of lists of the suggested products after each character of searchWord is typed. 

 

Example 1:

Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
Output: [
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
After typing mou, mous and mouse the system suggests ["mouse","mousepad"]



*/