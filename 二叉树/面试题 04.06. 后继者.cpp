面试题 04.06. 后继者

设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。

如果指定节点没有对应的“下一个”节点，则返回null。


一般树，非特定BST书非递归解法：
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> m;
        stack<TreeNode*> st;
        TreeNode *node = root;

        while (node != nullptr || !st.empty()) {
            while (node != nullptr) {
                st.push(node);
                node = node->left;
            }
            node = st.top(); st.pop();
            m.push_back(node);
            node = node->right;
        }

        
        for (int i = 0; i < m.size(); ++i) {
            if (m[i] == p) return i == m.size() - 1 ? nullptr : m[i + 1]; 
        }
        return nullptr;
    }
};

针对BST树的递归解法非常精妙：
https://leetcode-cn.com/problems/successor-lcci/solution/zhong-xu-bian-li-de-xia-yi-ge-yuan-su-5da-jie-fa-h/

首先本题中的二叉树还是个二叉搜索树，也就是中序遍历是单调递增的，所以我们可以利用这个性质来简化查找过程。

如果结点 p 的值大于等于 root 的值，说明 p 的后继结点在 root 右子树中，那么就递归到右子树中查找。
如果结点 p 的值小于 root 的值，说明 p 在 root 左子树中，而它的后继结点有两种可能，要么也在左子树中，要么就是 root：
如果左子树中找到了后继结点，那就直接返回答案。
如果左子树中没有找到后继结点，那就说明 p 的右儿子为空，那么 root 就是它的后继结点。

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL || p == NULL) return NULL;
        if (p->val >= root->val) {
            return inorderSuccessor(root->right, p);
        } else {
            TreeNode* left = inorderSuccessor(root->left, p);
            return left ? left : root;
        }
    }
};

