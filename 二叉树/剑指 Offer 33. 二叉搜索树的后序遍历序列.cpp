剑指 Offer 33. 二叉搜索树的后序遍历序列

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。

题解：

这道题的关键在于寻找第一个大于根节点的节点记为m。
这时候i到m-1就是左子树，m到j-1就是右子树。

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.empty()) return true;
        return recur(postorder, 0, postorder.size() - 1);    
    }

    bool recur(vector<int>& postorder, int i, int j) {
        if (i >= j) return true;
        int p = i;
        while (postorder[p] < postorder[j]) ++p;
        int m = p;
        while (postorder[p] > postorder[j]) ++p;
        return p == j && recur(postorder, i, m - 1) && recur(postorder, m, j - 1);
    }
};

