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
typedef pair<TreeNode*,int> pii;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> mp;

        queue<pii> q;
        q.push({root,0});

        while(!q.empty()){
            int currLvlSize = q.size();
            map<int,vector<int>> currLvlMp;

            while(currLvlSize--){
                TreeNode* currNode = q.front().first;
                int idx = q.front().second;
                q.pop();

                currLvlMp[idx].push_back(currNode->val);
                if(currNode->left) q.push({currNode->left,idx-1});
                if(currNode->right) q.push({currNode->right,idx+1});
            }
            
            for(auto&[idx, vec] : currLvlMp){
                sort(vec.begin(),vec.end());
                for(auto& x : vec) mp[idx].push_back(x);
            }
        }

        vector<vector<int>> res;
        for(auto& k : mp) res.push_back(k.second);
        return res;
    }
};