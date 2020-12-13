382. 链表随机节点

给定一个单链表，随机选择链表的一个节点，并返回相应的节点值。保证每个节点被选的概率一样。

进阶:
如果链表十分大且长度未知，如何解决这个问题？你能否使用常数级空间复杂度实现？

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        len = 0;
        this->head = head;
        ListNode *cur = head;
        while (cur) {
            cur = cur->next;
            ++len;
        }        
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int n = random() % len;
        ListNode *cur = head;
        while (n) {
            cur = cur->next;
            --n;
        }
        return cur->val;
    }

private:
    int len;
    ListNode *head;
};
