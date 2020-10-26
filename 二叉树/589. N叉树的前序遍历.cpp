589. N叉树的前序遍历

/*
 * Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorder(res, root);         
        return res;
    }
    
    void preorder(vector<int>& res, Node* root) {
        if (!root) return;
        res.push_back(root->val);
        for (int i = 0; i < root->children.size(); ++i) {
            preorder(res, root->children[i]);
        }
    }
};
