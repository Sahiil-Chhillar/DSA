/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int rob(TreeNode* root) {
        pair<int, int> res = dfs(root); // {maxTake, maxNotTake}
        return max(res.first, res.second);
    }

    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int take = root->val + left.second + right.second;
        int skip = max(left.first, left.second) + max(right.first, right.second);

        return {take, skip};
    }
};