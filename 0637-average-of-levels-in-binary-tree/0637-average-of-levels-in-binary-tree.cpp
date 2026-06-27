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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int currLvlSize = q.size();
            double currLvlSum = 0;
            for(int i = 0 ; i < currLvlSize;i++){
                TreeNode* currNode = q.front();
                q.pop();

                currLvlSum += currNode->val;
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
            result.push_back(currLvlSum/currLvlSize);
        }

        return result;
    }
};