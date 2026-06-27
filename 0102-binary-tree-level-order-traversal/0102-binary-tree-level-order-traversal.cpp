class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelOrderHelper(root, result);
        return result;
    }

private:
    void levelOrderHelper(TreeNode* root, vector<vector<int>>& result) {
        if (root == nullptr)
            return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = q.front();
                q.pop();
                currentLevel.push_back(currentNode->val);

                if (currentNode->left != nullptr)
                    q.push(currentNode->left);
                if (currentNode->right != nullptr)
                    q.push(currentNode->right);
            }
            result.push_back(currentLevel);
        }
    }
};