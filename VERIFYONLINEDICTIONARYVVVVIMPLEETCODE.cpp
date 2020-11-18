bool cmp(string& s1, string& s2, vector<int>& order){
	int n = s1.size();
	int m = s2.size();
	for(int i = 0; i < min(n, m); i++){
		if(order[s1[i] - 'a'] > order[s2[i] - 'a'])return true;
		else if(order[s1[i] - 'a'] < order[s2[i] - 'a'])return false;
	}
	if(n >= m)return true;
	else return false;
}

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
    	vector<int> v(26, 0);
        for(int i = 0; i < order.size(); i++){
        	v[order[i] - 'a'] = i;
        }
        for(int i = 0; i < words.size(); i++){
        	for(int j = 0; j < i; j++){
        		if(cmp(words[j], words[i], v))return false;
        	}
        }
        return true;
    }
};
// me
class Solution {
public:
    bool cmp(string &a,string &b,vector<int> &v)
    {
        int n = a.size();
        int m = b.size();
        int i,j,kl;
        for(i=0;i<min(n,m);i++)
        {
            if(v[a[i]-'a']>v[b[i]-'a'])
                return 1;
            else if(v[a[i]-'a']<v[b[i]-'a']) return 0;
        }
        if(n>=m)
            return 1;
        return 0;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int i,j,k,l;
        vector<int> v(26,0);
        for(i=0;i<26;i++)
            v[order[i]-'a']=i;
        for(i=1;i<words.size();i++)
        {
            for(j=0;j<i;j++)
            {
                if(cmp(words[j],words[i],v) ) return 0;
            }
        }
        return 1;
        
        
    }
};