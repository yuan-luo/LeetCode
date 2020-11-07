116. 填充每个节点的下一个右侧节点指针

给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
初始状态下，所有 next 指针都被设置为 NULL。

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeLinkNode* t = q.front();
                q.pop();
                if (i != n - 1) t->next = q.front();
                else t->next = NULL;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return;
    }
};
