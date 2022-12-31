82. 删除排序链表中的重复元素 II

给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        ListNode* pre = &dummy;
        while (pre->next) {
            ListNode* cur = pre->next;
            while (cur->next && cur->val == cur->next->val) cur = cur->next;
            if (cur != pre->next) pre->next = cur->next;
            else pre = pre->next;
        }
        return dummy.next;
    }
};
