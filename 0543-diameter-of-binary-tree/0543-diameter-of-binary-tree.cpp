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
    int maxLength = 0;
    int f(TreeNode* currNode){
        if(!currNode) return 0;
        int left = f(currNode->left);
        int right = f(currNode->right);

        maxLength = maxLength > (1 + left + right) ? maxLength : 1 + left+right;
        return left > right ? 1 + left : 1 +  right;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        f(root);
        return maxLength-1;
    }
};