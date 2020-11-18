/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 int noofnode(ListNode *h)
 {
     ListNode* st = h;
     int cnt=0;
     while(st!=NULL)
     {
         cnt++;
         st = st->next;
     }
     return cnt;
 }
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int n = noofnode(A);
    if(B>=n)
    {
        return A->next;
    }
    
    int c = n-B+1;
    ListNode *pre,*cur,*dummy;
    pre->val = 0;
    pre->next = A;
    dummy=pre;//www.interviewbit.com/problems/remove-nth-node-from-list-end/#
    cur = A;
    int i=1;
    while(i<c)
    {
        pre = cur;
    cur = cur->next;
    i++;
    }
    pre->next = cur->next;
    free(cur);//www.interviewbit.com/problems/remove-nth-node-from-list-end/#
    return dummy->next;
    
}
