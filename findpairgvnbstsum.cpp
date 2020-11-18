bool findpairUtil(Node* root, int sum,  unordered_set<int> &set) 
{ 
    if (root == NULL) 
        return false; 
  
    if (findpairUtil(root->left, sum, set)) 
        return true; 
  
    if (set.find(sum - root->data) != set.end()) { 
        cout << "Pair is found ("
             << sum - root->data << ", "
             << root->data << ")" << endl; 
        return true; 
    } 
    else
        set.insert(root->data); 
  
    return findpairUtil(root->right, sum, set); 
} 
  
void findPair(Node* root, int sum) 
{ 
    unordered_set<int> set; 
    if (!findpairUtil(root, sum, set)) 
        cout << "Pairs do not exit" << endl; 
}