99. 恢复二叉搜索树

二叉搜索树中的两个节点被错误地交换。
请在不改变其结构的情况下，恢复这棵树。

题解：

利用一个中序遍历找出数组的有序队列，然后对vals数组排序，中序遍历出来的BST结果一定是单调递增序列数组。
然后将list中错误的value对换一下。

class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> list;
        vector<int> vals;
        inorder(root, list, vals);
        sort(vals.begin(), vals.end());
        for (int i = 0; i < list.size(); ++i) {
            list[i]->val = vals[i];
        }
    }

    void inorder(TreeNode *root, vector<TreeNode*>& list, vector<int>& vals) {
        if (root == nullptr) return;
        inorder(root->left, list, vals);
        list.push_back(root);
        vals.push_back(root->val);
        inorder(root->right, list, vals);
    }
};
