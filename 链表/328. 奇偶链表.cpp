328. 奇偶链表

给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。
请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *pre = head, *cur = head->next;
        while (cur != nullptr && cur->next != nullptr) {
            ListNode *tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;
            pre = pre->next;
            cur = cur->next;
        }
        return head;
    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* odd = head;
        ListNode* even = odd->next;
        ListNode* evenHead = odd->next;
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
