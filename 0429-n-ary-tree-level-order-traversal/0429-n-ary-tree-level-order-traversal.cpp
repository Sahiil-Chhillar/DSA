/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};

        vector<vector<int>> result;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int currLvlSize = q.size();
            vector<int> currLvl;
            for(int i = 0; i < currLvlSize;i++){
                Node* currNode = q.front();
                q.pop();

                currLvl.push_back(currNode->val);
                for(auto& child : currNode->children) q.push(child);
            }

            result.push_back(currLvl);
        }

        return result;

    }
};