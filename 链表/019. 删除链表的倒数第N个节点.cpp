19. 删除链表的倒数第N个节点

给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
    
题解分析：

这里设置两个指针slow和fast。注意slow指针指向dummy，所以slow->next才指向倒数第n个节点。

D->1->2->3->4->5
要删除4，slow是3。

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr && n == 1) return nullptr;
        ListNode dummy;
        dummy.next = head;
        ListNode *slow = &dummy, *fast = head;
        for (int i = 0; i < n; ++i) fast = fast->next;
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return dummy.next;
    }
};
