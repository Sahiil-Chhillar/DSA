/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int f(TreeNode* currNode){
        if(!currNode) return 0;
        if(!currNode->left && !currNode->right) return 1;

        int left = currNode->left != nullptr ? 1 + f(currNode->left) : 0;
        int right = currNode->right != nullptr ? 1 + f(currNode->right) : 0;

        return max(left,right);
    }
    int maxDepth(TreeNode* root) {
        return f(root);
    }
};