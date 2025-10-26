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
    int maxSum = -1e9;
    int f(TreeNode* root){
        if(!root) return 0;

        int leftSum = f(root->left);
        int rightSum = f(root->right);

        maxSum = maxSum > (root->val + leftSum + rightSum) ? maxSum :root->val + leftSum + rightSum;

        if(root->val + leftSum < 0 && root->val + rightSum < 0) return 0;
        return leftSum > rightSum ? root->val + leftSum : root->val + rightSum;
    }
    int maxPathSum(TreeNode* root) {
        f(root);
        return maxSum;
    }
};