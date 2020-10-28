501. 二叉搜索树中的众数

给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：

结点左子树中所含结点的值小于等于当前结点的值
结点右子树中所含结点的值大于等于当前结点的值
左子树和右子树都是二叉搜索树
例如：
给定 BST [1,null,2,2],

   1
    \
     2
    /
   2
返回[2].

提示：如果众数超过1个，不需考虑输出顺序

题解：

设计一个base, count和maxCount。
当当前值等于base时，count累加。

class Solution {
public:
    int base, count, maxCount;
    vector<int> ans;
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->left);
        update(root->val);
        dfs(root->right);
    }
    void update(int x) {
        if (x != base) {
            count = 1;
            base = x;
        } else {
            count++;
        }
        if (count == maxCount) ans.push_back(base);
        if (count > maxCount) {
            maxCount = count;
            ans = vector<int>{x};
        }
    }
};

