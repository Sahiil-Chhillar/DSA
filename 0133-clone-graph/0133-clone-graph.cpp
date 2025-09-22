/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> visitedNode;
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

            if (visitedNode.find(node) != visitedNode.end())
                return visitedNode[node];

            Node* clone = new Node(node->val);
            visitedNode[node] = clone;

            for (Node* neighbor : node->neighbors) {
                clone->neighbors.push_back(cloneGraph(neighbor));
            }

            return clone;
    }
};