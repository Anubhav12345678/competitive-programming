struct TrieNode{
    int frequency;
    TrieNode *arr[26];
    TrieNode(){
        frequency = 0;
        for(int i=0;i<26;i++){
            arr[i] = NULL;
        }
    }
};

void add(TrieNode * root,string str,int ind){
    if(ind == str.size())
        return;
    if(root->arr[str[ind]-'a'] == NULL)
        root->arr[str[ind]-'a'] = new TrieNode();
    root->arr[str[ind]-'a']->frequency++;
    add(root->arr[str[ind]-'a'],str,ind+1);
}

int search(TrieNode* root,string s, int ind){
    if(root->arr[s[ind]-'a']->frequency == 1)
        return ind;
    if(root->arr[s[ind]-'a'] != NULL){
        return search(root->arr[s[ind]-'a'],s,ind+1);
    }
    return -1;
}
vector<string> Solution::prefix(vector<string> &A) {
    int n = A.size();
    TrieNode * root = new TrieNode;
    for(int i=0;i<n;i++){
        add(root,A[i],0);
    }
    vector<string> res;
    for(int i=0;i<A.size();i++){
        int ind = search(root,A[i],0);
        string s = "";
        for(auto elem:A[i]){
            if(ind <0){
                break;
            }
            s += elem;
            ind--;
        }
        res.push_back(s);
    }
    return res;
}
