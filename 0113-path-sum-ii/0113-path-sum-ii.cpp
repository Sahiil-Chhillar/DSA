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
    void f(TreeNode* currNode, int targetSum , int currSum , vector<int>& path,vector<vector<int>>& res){
        if(!currNode) return;

        currSum += currNode->val;
        path.push_back(currNode->val);

        if(!currNode->left && !currNode->right && currSum == targetSum) res.push_back(path);

        f(currNode->left,targetSum,currSum,path,res);
        f(currNode->right,targetSum,currSum,path,res);

        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        f(root,targetSum,0,path,res);
        return res;
    }
};