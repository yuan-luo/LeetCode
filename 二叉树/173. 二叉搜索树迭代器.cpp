173. 二叉搜索树迭代器

利用递归中序遍历。

class BSTIterator {
public:
    vector<int> nodes;
    int index;
    BSTIterator(TreeNode* root) {
        index = -1;
        inorder(root);
    }

    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
    }
    
    /** @return the next smallest number */
    int next() {
        return nodes[++index];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index + 1 < nodes.size();
    }
    
};

