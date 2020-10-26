230. 二叉搜索树中第K小的元素

给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        st.push(root);
        TreeNode *p = root;
        while (p || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->left;
            }
            TreeNode *node = st.top(); st.pop();
            p = node;
            --k;
            if (k == 0) return p->val;
            p = p->right;
        }
        return 0;
    }
};
