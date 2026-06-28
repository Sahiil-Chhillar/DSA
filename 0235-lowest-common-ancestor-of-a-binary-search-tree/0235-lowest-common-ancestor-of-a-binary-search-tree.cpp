/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // LCA only changes if both p and q are on same side of root 
        while (root) {
            if (p->val > root->val && q->val > root->val) root = root->right;
            else if (p->val < root->val && q->val < root->val) root = root->left;
            else return root;
        }
        return nullptr;        
    }
};