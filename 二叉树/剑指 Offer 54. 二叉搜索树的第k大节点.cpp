剑指 Offer 54. 二叉搜索树的第k大节点

中序遍历

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        TreeNode *p = root;
        stack<TreeNode*> st;
        vector<int> ans;
        while (!st.empty() || p != nullptr) {
            while (p != nullptr) {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            ans.push_back(p->val);
            p = p->right;
        }
        return ans[ans.size() - k];
    }
};

