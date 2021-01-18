147. 对链表进行插入排序

对链表进行插入排序。

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        ListNode *cur = head, *pre = &dummy;
        while (cur != nullptr) {
            if (cur->next != nullptr && cur->next->val < cur->val) {
                // cur->next为需要插入链表的节点
                while (pre->next != nullptr && pre->next->val < cur->next->val) pre = pre->next;
                // 现在需要把cur->next移动到pre和它的下一个节点之间
                ListNode *tmp = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = tmp;
                pre = &dummy;
            } else cur = cur->next;
        }
        return dummy.next;
    }
};

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
