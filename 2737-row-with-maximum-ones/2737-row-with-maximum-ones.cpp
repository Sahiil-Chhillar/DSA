class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans;
        int max1 = 0;

        for(int i = 0 ;i < mat.size();i++){
            int cnt = 0;
            for(int j = 0 ; j < mat[0].size();j++){
                if(mat[i][j] == 1) cnt++;
            }

            max1 = max(max1,cnt);
        }

        for(int i = 0 ;i < mat.size();i++){
            int cnt = 0;
            for(int j = 0 ; j < mat[0].size();j++){
                if(mat[i][j] == 1) cnt++;
            }
            if(cnt == max1){
                ans.push_back(i);
                ans.push_back(cnt);
                break;
            } 
        }

        return ans;
    }
};