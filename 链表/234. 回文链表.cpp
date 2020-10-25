234. 回文链表

请判断一个链表是否为回文链表。

==========================================

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow = head, *fast = head;
        stack<int> s;
        s.push(slow->val);
        while (fast->next && fast->next->next) {
            slow = slow->next;
            s.push(slow->val);
            fast = fast->next->next;
        }
        if (!fast->next) s.pop();
        while (slow->next) {
            slow = slow->next;
            int temp = s.top(); s.pop();
            if (temp != slow->val) return false;
        }
        return true;
    }
};
