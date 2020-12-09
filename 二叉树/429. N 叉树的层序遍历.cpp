429. N 叉树的层序遍历

给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。

树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> out;
            for (int i = q.size(); i > 0; --i) {
                Node* node = q.front(); q.pop();
                out.push_back(node->val);
                if (!node->children.empty())
                    for (int i = 0; i < node->children.size(); ++i) q.push(node->children[i]);
            }
            ans.push_back(out);
        }
    return ans;
    }
};
