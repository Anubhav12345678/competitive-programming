/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 int noofnode(ListNode* v)
 {
     if(v==NULL)
     return 0;
     return 1+noofnode(v->next);
 }
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode *prev=A;
    ListNode *cur = A;
    int n= noofnode(A);
    if(n==1)
    return A;
    prev=A;
    cur = A->next;
    while(cur!=NULL)
    {
        int t = prev->val;
        prev->val = cur->val;
        cur->val = t;
        if(cur->next)
        {
            prev = cur->next;
            cur = cur->next->next;
        }
        else
        return A;
    }
    return A;
}


//LEETCODE VVIMP SOLUTION
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void swap(int *a,int *b)
    {
        int t  =*a;
        *a=*b;
        *b=t;
    }
    void solve(ListNode *h)
    {
        if(h!=NULL&&h->next!=NULL)
        {
            swap(&(h->val),&(h->next->val));
            solve(h->next->next);
        }
    }
    ListNode* swapPairs(ListNode* head) {
        solve(head);
        return head;
    }
};