133. 克隆图

给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。

图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。

class Node {
    public int val;
    public List<Node> neighbors;
}

class Solution {
public:
    unordered_map<Node*, Node*> visited; // old -> new
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;
        if (visited.find(node) != visited.end()) return visited[node];
        Node *cloneNode = new Node(node->val);
        visited[node] = cloneNode;
        for (int i = 0; i < node->neighbors.size(); ++i) {
            cloneNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return cloneNode;
    }
};
