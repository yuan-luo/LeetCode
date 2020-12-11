面试题 02.03. 删除中间节点

实现一种算法，删除单向链表中间的某个节点（即不是第一个或最后一个节点），假定你只能访问该节点。

class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node->next == nullptr) {
            node = nullptr;
        } else {
            node->val = node->next->val;
            node->next = node->next->next;
        }
    }
};
