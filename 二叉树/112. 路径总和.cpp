112. 路径总和

给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        
        stack<TreeNode*> st;
        stack<int> tsum;
        
        st.push(root);
        tsum.push(root->val);
        
        while (!st.empty()) {
            TreeNode *node = st.top(); st.pop();
            int ts = tsum.top(); tsum.pop();
            
            if (node->left == NULL && node->right == NULL && sum == ts) return true;
            if (node->left) {
                st.push(node->left);
                tsum.push(ts + node->left->val);
            }
            if (node->right) {
                st.push(node->right);
                tsum.push(ts + node->right->val);
            }            
        }
        return false;
    }
};


我的写法：
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        stack<TreeNode*> st;
        stack<TreeNode*> st_sum;
        
        if (root == nullptr) return false;
        st.push(root);
        st_sum.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top(); st.pop();
            TreeNode* node_sum = st_sum.top(); st_sum.pop();
            if (node->left == nullptr && node->right == nullptr && node_sum->val == sum) return true;
            if (node->right) {
                st.push(node->right);
                node->right->val += node->val;
                st_sum.push(node->right);
            }
            if (node->left) {
                st.push(node->left);
                node->left->val += node->val;
                st_sum.push(node->left);                
            }
        }
        return false;
    }
};
