173. 二叉搜索树迭代器

解法一：利用递归中序遍历

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

解法二：非递归中序遍历

设计一个栈。
迭代器重点在于怎么运用中序遍历，先把左边的压入栈中后，栈顶元素就是最小的元素；
当调用next()函数的时候，需要检查当前取出的节点是否有右子树，右子树的节点都比它大，
但比它的父亲小，所以它出栈后，要把它右边的所有节点都压入栈中。

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *node = st.top();
        st.pop();
        int val = node->val;
        node = node->right;
        while (node) {
            st.push(node);
            node = node->left;
        }
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    stack<TreeNode*> st;
};
