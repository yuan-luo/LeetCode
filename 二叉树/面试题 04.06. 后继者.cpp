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
