101. 对称二叉树

给定一个二叉树，检查它是否是镜像对称的。

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode*> q1, q2;
        q1.push(root->left); q2.push(root->right);
        while (!q1.empty() && !q2.empty()) {
            TreeNode *node1 = q1.front(); q1.pop();
            TreeNode *node2 = q2.front(); q2.pop();
            if ((node1 && !node2) || (!node1 && node2)) 
                return false;
            if (node1 != nullptr) {
                if (node1->val != node2->val) return false;
                q1.push(node1->left);
                q2.push(node2->right);
                q1.push(node1->right);
                q2.push(node2->left);
            }

        }
        return true;
    }
};


class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (left && !right || !left && right || 
            left->val != right->val) return false;
        return isSymmetric(left->left, right->right) && 
            isSymmetric(left->right, right->left);
    }
    
};
