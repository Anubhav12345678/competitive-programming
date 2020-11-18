class WordDictionary {
public:
    class TrieNode
    {
        public:
        bool isword;
        TrieNode* child[26];
        TrieNode()
        {
            isword=0;
            memset(child,NULL,sizeof(child));
        }
    };
    TrieNode* head= NULL;
    /** Initialize your data structure here. */
    WordDictionary() {
        head=new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* cur=head;
        int n = word.size();
        for(int i=0;i<n;i++)
        {
            char c = word[i];
            if(cur->child[c-'a']==NULL)
            {
                cur->child[c-'a'] = new TrieNode();
            }
            cur = cur->child[c-'a'];
        }
        cur->isword=1;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(word,head,0);
    }
    bool dfs(string s,TrieNode* cur,int ind)
    {
        if(cur==NULL||ind>s.size()) return 0;
        if(ind==s.size())
        {
            if(cur->isword) return 1;
            return 0;
        }
        char c = s[ind];
        if(c=='.')
        {
            for(int i=0;i<26;i++)
            {
                if(dfs(s,cur->child[i],ind+1))
                    return 1;
            }
            return 0;
        }
        return dfs(s,cur->child[c-'a'],ind+1);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */