160. 相交链表

https://leetcode-cn.com/problems/intersection-of-two-linked-lists/

编写一个程序，找到两个单链表相交的起始节点。

注意：

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

题解：

链表A走了：a + c
链表B走了：b + c
当A走到头时候再从B开始走起，
当B走到头时候再从A开始走起。
这样两者一定会在c的开始处相遇，因为他们都走了a + b + c的距离。

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = a == nullptr ? headB : a->next;
            b = b == nullptr ? headA : b->next;
        }
        return a;
    }
};
