147. 对链表进行插入排序

对链表进行插入排序。

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(-1);
        ListNode *cur = head;
        while (cur != nullptr) {
            // cur是要被检查的节点，pos是整个链表的游标，因为每次都要从头开始检查
            ListNode *pos = &dummy;
            while (pos->next != nullptr && cur->val >= pos->next->val) pos = pos->next;
            ListNode *tmp = pos->next;
            pos->next = cur;
            cur = cur->next;
            pos->next->next = tmp;
        }
        return dummy.next;
    }
};

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
