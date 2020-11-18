class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        // result vector
        vector<ListNode*> rst(k, nullptr);
        // trival case: empty list
        if (!root) {
            return rst;
        }
        // get length of the list
        ListNode* tmp = root;
        int N = 0;
        while (tmp) {
            tmp = tmp->next;
            N += 1;
        }
        // determine length for each segment
        vector<int> seg(k, N / k);
        for (int i(0); i < N % k; ++i) {
            seg[i] += 1;
        }
        // construct result list by spliting the original 
        ListNode* last;
        tmp = root;
        for (int i(0); i < k; ++i) {
            if (seg[i] == 0) break;
            rst[i] = tmp;
            for (int j(0); j < seg[i]; ++j) {
                last = tmp;
                tmp = tmp->next;
            }
            last->next = nullptr;
        }
        return rst;
    }
};