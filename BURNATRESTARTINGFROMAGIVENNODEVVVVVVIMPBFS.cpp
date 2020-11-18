const int nax = 100*1000 + 10;
 vector<int> G[nax];
 /*
Given a binary tree denoted by root node A and a leaf node B from this tree.

It is known that all nodes connected to a given node (left child, right child and parent) get burned in 1 second.
 Then all the nodes which are connected through one intermediate get burned in 2 seconds, and so on.

You need to find the minimum time required to burn the complete binary tree.
 */
int Solution::solve(TreeNode* A, int B) {
    for(int i = 0;i<nax;++i){
        G[i].clear();
    }
    
    queue<TreeNode *> q;
    q.push(A);
    int n  = 0;
    
    while(!q.empty()){
        TreeNode * f = q.front();
        q.pop();
        int u = f->val;
        ++n;
        if(f->left){
            int v = f->left->val;
            G[u].push_back(v);
            G[v].push_back(u);
            q.push(f->left);
        }
        if(f->right){
            int v = f->right->val;
            G[u].push_back(v);
            G[v].push_back(u);
            q.push(f->right);
        }
    }
    
    
    int times = 0 , cnt = 1;
    queue<int> qq;
    qq.push(B);
    vector<bool> vis(nax , false);
    vis[B] = 1;
    
    while(!qq.empty()){
        int sz = qq.size();
        if(cnt == n){
            break;
        }
        for(int x =  0;x<sz;++x){
            int f= qq.front();
            qq.pop();
           
            for(int to : G[f]){
                if(!vis[to]){
                    cnt++;
                    qq.push(to);
                    vis[to] = 1;
                }
            }
        }
            
        
        ++times;
    }
    return times;
    
    
    
    
    
}

