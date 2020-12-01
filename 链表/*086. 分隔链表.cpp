86. 分隔链表

给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

题解：

这道题就是把原链表分割成两个链表，一个小于x，一个大于等于x。然后依次排序插入节点，最后再把它们接起来。

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(-1);
        ListNode dummy2(-1);
        ListNode *l1 = &dummy1;
        ListNode *l2 = &dummy2;
        while (head != nullptr) {
            if (head->val < x) {
                l1->next = head;
                l1 = l1->next;
            } else {
                l2->next = head;
                l2 = l2->next;
            }
            head = head->next;
        }
        l1->next = dummy2.next;
        l2->next = nullptr;
        return dummy1.next;
    }
};
