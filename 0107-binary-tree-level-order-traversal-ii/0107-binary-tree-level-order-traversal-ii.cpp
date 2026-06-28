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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int currLvlSize = q.size();
            vector<int> currLvl;
            while(currLvlSize--){
                TreeNode* currNode = q.front();
                q.pop();
                currLvl.push_back(currNode->val);
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
            res.push_back(currLvl);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};