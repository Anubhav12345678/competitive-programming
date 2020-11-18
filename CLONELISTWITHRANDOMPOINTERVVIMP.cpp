/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node * createnode(Node * srcnode)
    {
        Node * cpy = new Node(srcnode->val,NULL,NULL);
        return cpy;
    }
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        Node* tmp = head;
        map<Node*,Node*> hash;
        while(tmp)
        {
            hash[tmp] = createnode(tmp);
            tmp=tmp->next;
        }
        tmp=head;
        while(tmp)
        {
            Node *clone = hash[tmp];
            clone->next = hash[tmp->next];
            clone->random = hash[tmp->random];
            tmp=tmp->next;
        }
        return hash[head];
    }
};