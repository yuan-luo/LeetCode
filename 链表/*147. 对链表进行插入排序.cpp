147. 对链表进行插入排序

对链表进行插入排序。

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode* cur = head;
        ListNode* pre = &dummy;
        ListNode* next = nullptr;
        while (cur != nullptr) {
            next = cur->next;
            while (pre->next != nullptr && pre->next->val <= cur->val) pre = pre->next;

            cur->next = pre->next;
            pre->next = cur;
            pre = &dummy;
            cur = next;
        }
        return dummy.next;
    }
};
