剑指 Offer 36. 二叉搜索树与双向链表

https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/

### 解题思路

这道题的一个关键是设计一个全局prev节点指针。
利用递归中序遍历处理中间节点双向相连，
利用构造一个dummy指针处理首尾节点连接。

最后返回dummy->next。

### 代码

class Solution {
public:

    Node* prev = nullptr;
    Node* treeToDoublyList(Node* root) {
        // corner case:
        if (root == nullptr) return nullptr;
        Node *dummy = new Node(0, nullptr, nullptr);
        prev = dummy;
        // 把nodes全部连起来
        helper(root);
        // 把头尾连起来
        prev->right = dummy->right;
        dummy->right->left = prev;
        return dummy->right;
    }

    void helper(Node* cur) {
        if (cur == nullptr) return;
        helper(cur->left);
        prev->right = cur;
        cur->left = prev;
        prev = cur;
        helper(cur->right);
    }
};
