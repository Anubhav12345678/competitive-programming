/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

/*

You are given a perfect binary tree where all leaves are on the same level, and every parent has two children.
 The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.


*/
class Solution {
public:
     Node* getnext(Node* p)
    {
        Node* tmp = p->next;
         while(tmp!=NULL)
         {
             if(tmp->left!=NULL)
                 return tmp->left;
             if(tmp->right!=NULL)
                 return tmp->right;
             tmp = tmp->next;
         }
         return NULL;
    }
    void solve(Node* r)
    {
        if(!r)
            return;
        Node* tmp;
        r->next=NULL;
        while(r!=NULL)
        {
            Node* q= r;
            while(q)
            {
                if(q->left)
                {
                    if(q->right)
                    {
                        q->left->next=q->right;
                    }
                    else
                        q->left->next = getnext(q);
                }
                if(q->right)
                    q->right->next = getnext(q);
                q=q->next;
            }
            if(r->left)
                r=r->left;
            else if(r->right)
                r=r->right;
            else
                r=r->next;
        }
    }
    Node* connect(Node* root) {
        solve(root);
        return root;
    }
};