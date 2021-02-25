701. 二叉搜索树中的插入操作

给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 
返回插入后二叉搜索树的根节点。 
输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。

注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 
你可以返回 任意有效的结果 。

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode* root = new TreeNode(val);
            return root;
        }
        TreeNode *node;
        if (val < root->val) root->left = insertIntoBST(root->left, val);
        else root->right = insertIntoBST(root->right, val);
        return root;
    }
};

非递归解法：

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) { root = new TreeNode(val); return root; }
        TreeNode *cur = root;
        while (true) {
            if (val < cur->val) {
                if (cur->left == nullptr) { 
                    cur->left = new TreeNode(val); 
                    break; 
                }
                cur = cur->left;
            } else {
                if (cur->right == nullptr) {
                    cur->right = new TreeNode(val); 
                    break; 
                }
                cur = cur->right;
            }
        }
        return root;
    }
};
