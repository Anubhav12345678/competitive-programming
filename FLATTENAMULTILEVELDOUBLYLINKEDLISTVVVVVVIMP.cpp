/*
You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.


*/


class Solution {
public:
    Node* flatten(Node* head) {
        dfs(head);
        return head;
    }
    Node* dfs(Node* r) {
        Node *cur = r, *prev;
        while (cur) {
            if (cur->child) {
                Node *last = dfs(cur->child);
                Node *curNext = cur->next;
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = NULL;
                last->next = curNext;
                if (curNext) curNext->prev = last;
            }    
            prev = cur;
            cur = cur->next;
        }
        return prev;
    }
};