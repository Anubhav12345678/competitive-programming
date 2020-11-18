

/*

Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""




*/
//meee
class Solution {
public:
    string reorganizeString(string s) {
        int i,j,k,l,n=s.size();
        priority_queue<pair<int,char>> pq;
        map<char,int> mp;
        for(auto c:s)
            mp[c]++;
        for(auto it:mp)
            pq.push({it.second,it.first});
        string res;
        pair<int,char> p1,p2;
        while(!pq.empty())
        {
            p1 = pq.top();
            pq.pop();
            res+=p1.second;
            if(!pq.empty())
            {
                res+=pq.top().second;
                p2 = pq.top();
                pq.pop();
                if(p2.first>1)
                    pq.push({p2.first-1,p2.second});
            }
            if(p1.first>1)
            pq.push({p1.first-1,p1.second});
        }
        for(i=1;i<n;i++) if(res[i]==res[i-1]) return "";
        return res;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> m;
        int i,j,k,l;
        for(i=0;i<s.size();i++)
            m[s[i]]++;
        priority_queue<pair<int,char>> pq;
        for(auto it=m.begin();it!=m.end();it++)
            pq.push(make_pair(it->second,it->first));
        int p = (s.size()%2==0)?(s.size()/2):(s.size()/2+1);
        int idx=0;
        while(!pq.empty())
        {
            pair<int,char> pii = pq.top();
            pq.pop();
            if(pii.first>p)
                return "";
            // int idx=0;
            for(i=0;i<pii.first;i++)
            {
                s[idx]=pii.second;
                idx = (idx+2>=s.size())?1:(idx+2);
            }
        }
        return s;
    }
};


class Solution {
public:
    string reorganizeString(string S) {
       unordered_map<char, int> M;
	for (int i = 0; i < S.size(); i++) {
		auto it = M.find(S[i]);
		if (it == M.end()) M.insert(make_pair(S[i], 1));
		else it->second++;
	}
	
	priority_queue<pair<int,char>> PQ;
	for (auto it = M.begin(); it != M.end(); it++) 
		PQ.push(make_pair(it->second, it->first));
	
	pair<int, char> P;
	int idx = 0, thr = S.size()%2==0?(S.size()/2):(S.size()/2+1);
	while (!PQ.empty()) {
		P = PQ.top(); PQ.pop();
		if (P.first > thr) return string("");
		for (int i = 0; i < P.first; i++) {
			S[idx] = P.second;
            idx=idx+2>=S.size()?1:idx+2;
		}
	}
	return S;
    }
};