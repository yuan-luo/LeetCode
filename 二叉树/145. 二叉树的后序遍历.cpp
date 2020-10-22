145. 二叉树的后序遍历

https://leetcode-cn.com/problems/binary-tree-postorder-traversal/

给定一个二叉树，返回它的 后序 遍历。

题解：
后序遍历是三种遍历中最复杂的一种。
两种解法：迭代和中序之后反转。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode *head = root;
        while(!st.empty()) {
            TreeNode *p = st.top();
            if ( (p->left == NULL && p->right == NULL) || p->left == head || p->right == head) {
                st.pop();
                res.push_back(p->val);                
                head = p;
            } else {
                if (p->right) st.push(p->right);
                if (p->left) st.push(p->left);   
            }           
        }
        return res;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        
        while (!nodeStack.empty()) {
            TreeNode *node = nodeStack.top();
            res.push_back(node->val);
            nodeStack.pop();
            if (node->left) 
                nodeStack.push(node->left);
            if (node->right)
                nodeStack.push(node->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
