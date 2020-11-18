/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* solve1(ListNode* h,int k,bool f)
{
    if(!h) return h;
    if(f)// we need to rev this set;
    {
        ListNode* cur=h,*next,*pre=NULL;
        int i=0;
        while(cur&&i<k)
        {
            next = cur->next;
            cur->next = pre;
            pre=cur;
            cur=next;
            i++;
        }
        ListNode* x = solve1(cur,k,!f);
        h->next = x;
        return pre;
    }
    else
    {
        int i=0;
        ListNode* cur=h,*pre;
        while(cur&&i<k)
        {
            pre=cur;
            cur=cur->next;
            i++;
        }
        pre->next  =solve1(cur,k,!f);
        return h;
    }
}
ListNode* Solution::solve(ListNode* A, int B) {
    return solve1(A,B,true);
}
