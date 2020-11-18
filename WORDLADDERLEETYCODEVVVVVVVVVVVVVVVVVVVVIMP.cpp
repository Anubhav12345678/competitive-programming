/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of 
shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.



*/



struct node{
  string s;
  int dis;
};

class Solution {
public:

    int ladderLength(string bw, string ew, vector<string>& wordList) {
        unordered_set<string> st;
        int i,j,k,l,n=bw.size();
        int m = wordList.size();
        for(i=0;i<m;i++){
            st.insert(wordList[i]);
        }
        
        queue<node> q;
        node cur;
        cur.s = bw;
        cur.dis=1;
        q.push(cur);
        set<string> vis;
        while(!q.empty()){
            node p = q.front();
            q.pop();
            if(p.s==ew)
                return p.dis;
            vis.insert(p.s);
            string v = p.s;
            for(i=0;i<n;i++){
                char c = v[i];
                for(j=0;j<26;j++){
                   char c2 = j+'a';
                    if(c!=c2){
                        v[i]=c2;
                        if(st.find(v)!=st.end()){
                            q.push({v,p.dis+1});
                            st.erase(v);
                        }
                    }
                }
                v[i]=c;
            }
        }
        
        return 0;
    }
};