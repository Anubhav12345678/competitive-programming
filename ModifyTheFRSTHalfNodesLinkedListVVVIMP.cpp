/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void reverse(ListNode **a)
{
    ListNode *cur = *a;
    ListNode *prev = NULL;
    while(cur!=NULL)
    {
        ListNode *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *a = prev;
}
int noofnodes(ListNode *a)
{
    if(a==NULL)
    return 0;
    int cnt=0;
    while(a)
    {
        cnt++;
        a=a->next;
    }
}
ListNode* Solution::subtract(ListNode* A) {
    if(!A||(A->next)==NULL)
    return A;
    ListNode *cur,*sl,*fs,*prev=NULL;
    sl = A;
    fs = A;
    while(fs&&fs->next)
    {
        prev=sl;
        sl = sl->next;
        fs = fs->next->next;
    }
    int n = noofnodes(A);
    if(n%2)
    {
    sl = sl->next;
    prev=prev->next;
    }
    reverse(&sl);
    prev->next=sl;
    cur = sl;
    ListNode *h = A;
    while(h&&cur&&(h!=sl))
    {
        h->val = (cur->val)-(h->val);
        h=h->next;
        cur = cur->next;
    }
    reverse(&sl);
    prev->next=sl;
    return A;
    
}
