class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>> mp;
        for(int i = 0 ; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }

        int flag = false;
        vector<int> ans;
        for(auto& f : mp){
            if(flag){
                ans.insert(ans.end(),f.second.begin(),f.second.end());
                flag = !flag;
            }
            else{
                reverse(f.second.begin(),f.second.end());
                ans.insert(ans.end(),f.second.begin(),f.second.end());
                flag = !flag;
            }
        }
        return ans;
    }
};