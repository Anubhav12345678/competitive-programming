class Trie {
public:
/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.


*/
    set<string> st1,st2;
    /** Initialize your data structure here. */
    Trie() {
        st1.clear();
        st2.clear();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        st1.insert(word);
        for(int i=1;i<=word.size();i++)
            st2.insert(word.substr(0,i));
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return st1.find(word)!=st1.end();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return st2.find(prefix)!=st2.end();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */