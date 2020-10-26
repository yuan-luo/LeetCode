92. 反转链表 II

反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

https://leetcode-cn.com/problems/reverse-linked-list-ii/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        for (int i = 1; i < m; ++i) prev = prev->next;
        ListNode* cur = prev->next;
        for (int i = m; i < n; ++i) {
            ListNode *move = cur->next;
            cur->next = move->next;
            move->next = prev->next;
            prev->next = move;
        }
        return dummy->next;
    }
};
