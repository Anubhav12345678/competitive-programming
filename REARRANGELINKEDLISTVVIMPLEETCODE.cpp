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
    void reverse(ListNode **head)
    {
        ListNode *cur = *head,*pre=NULL,*next;
        while(cur)
        {
            next = cur->next;
            cur->next = pre;
            pre=cur;
            cur=next;
        }
        *head=pre;
    }
    void rearrange(ListNode **head)
    {
        ListNode *sl = *head,*fs = *head;
        while(fs&&fs->next)
        {
            sl=sl->next;
            fs=fs->next->next;
        }
        ListNode *head1= *head;
        ListNode *head2 = sl->next;
        sl->next=NULL;
        reverse(&head2);
        *head = new ListNode(0);
        ListNode *cur = *head;
        while(head1||head2)
        {
            if(head1)
            {
                cur->next = head1;
                head1=head1->next;
                cur=cur->next;
            }
            if(head2)
            {
                cur->next = head2;
                head2=head2->next;
                cur=cur->next;
            }
        }
        (*head) = (*head)->next;
        
    }
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return;
            
        rearrange(&head);
    }
};S