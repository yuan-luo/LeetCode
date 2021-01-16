24. 两两交换链表中的节点

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *tmp = head->next;
        head->next = swapPairs(tmp->next);
        tmp->next = head;
        return tmp;
    }
};
