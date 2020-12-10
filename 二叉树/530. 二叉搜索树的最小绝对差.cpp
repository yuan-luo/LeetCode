530. 二叉搜索树的最小绝对差

给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* p = root;
        int ans = INT_MAX; TreeNode* pre = nullptr;
        while (p != nullptr || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->left;
            }
            p = st.top(); st.pop();
            if (pre != nullptr) ans = min(ans, p->val - pre->val);
            pre = p;
            p = p->right;
        }
        return ans;
    }
};
