/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
To avoid making a copy of the entire vector, always pass vectors as reference parameters.
It is much faster. Not only are references only 4 bytes long, but copying a vector means dynamically allocating
 new memory for a new vector, copying all elements, and then deallocating this memory when the function returns.

*/
vector<int> v;
void fill(ListNode* h)
{
    if(!h)
    return;
    v.push_back(h->val);
    fill(h->next);
}
TreeNode* solve(vector<int> &a,int l,int r)// yhe pe address k sath vec pass krna nhi to tle aaa jayegi
{
    if(l>r)
    return NULL;
    int m =(l+r)/2;
    TreeNode* cur = new TreeNode(a[m]);
    cur->left = solve(a,l,m-1);
    cur->right = solve(a,m+1,r);
    return cur;
}
TreeNode* Solution::sortedListToBST(ListNode* A) {
    if(!A)
    return NULL;
    v.clear();
    fill(A);
    int n = v.size();
    return solve(v,0,n-1);
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
