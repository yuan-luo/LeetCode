105. 从前序与中序遍历序列构造二叉树

根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft, int inRight) {
        if (preLeft > preRight || inLeft > inRight) return nullptr;
        int pIndex = 0;
        for (int i = inLeft; i <= inRight; ++i) {
            if (preorder[preLeft] == inorder[i]) {
                pIndex = i;
                break;
            }
        }
        TreeNode *root = new TreeNode(preorder[preLeft]);
        root->left = buildTree(preorder, preLeft + 1, pIndex - inLeft + preLeft, inorder, inLeft, pIndex - 1);
        root->right = buildTree(preorder, pIndex - inLeft + preLeft + 1, preRight, inorder, pIndex + 1, inRight);
        return root;
    }
};
