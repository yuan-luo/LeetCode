590. N叉树的后序遍历

给定一个 N 叉树，返回其节点值的后序遍历。

例如，给定一个 3叉树 :

返回其后序遍历: [5,6,3,2,4,1]. 

说明: 递归法很简单，你可以使用迭代法完成此题吗?

题解：

递归法真的简单吗？

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        postorder(res, root);
        return res;
    }
    
    void postorder(vector<int>& res, Node* root) {
        if (!root) return;
        for (int i = 0; i < root->children.size(); ++i) {
            postorder(res, root->children[i]);
        }
        res.push_back(root->val);        
    }
};
