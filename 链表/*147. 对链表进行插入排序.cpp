147. 对链表进行插入排序

对链表进行插入排序。

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy; 
        ListNode *cur = nullptr;
        while (head) {
            cur = &dummy;
            while (cur->next && cur->next->val <= head->val) {
                cur = cur->next;
            }
            ListNode *tmp = head->next;
            head->next = cur->next;
            cur->next = head;
            head = tmp;
        }
        return dummy.next;
    }
};
