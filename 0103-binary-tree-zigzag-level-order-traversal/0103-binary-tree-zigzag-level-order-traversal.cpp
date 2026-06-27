/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == nullptr)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (q.empty() != true) {
            int size = q.size();
            vector<int> temp(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // index at which value is to be stored
                int index = (leftToRight) ? i : (size - 1 - i);
                temp[index] = node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            // level completed change direction
            leftToRight = !leftToRight;
            result.push_back(temp);
        }
        return result;
    }
};