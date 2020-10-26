94. 二叉树的中序遍历

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top(); s.pop();
            res.push_back(p->val);
            p = p->right;
        }
        return res;
    }
};

我的写法：

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        TreeNode *p = root;
        while (p) {
            st.push(p);
            p = p->left;
        }

        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            
            ans.push_back(node->val);
            node = node->right;
            while (node) {
                st.push(node);
                node = node->left;
            }
        }
        return ans;
    }
    stack<TreeNode*> st;
};
