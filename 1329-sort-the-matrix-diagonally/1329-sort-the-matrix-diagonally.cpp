class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        // int rows = mat.size();
        // int cols = mat[0].size();
        // for(int i = 0 ; i < cols ; i++){
        //     vector<int> v;
        //     int r = 0;
        //     int c = i;
        //     while(r <= rows-1 && c <= cols-1){
        //         v.push_back(mat[r][c]);
        //         r++;c++;
        //     }

        //     sort(v.begin(),v.end());
        //     r = 0;
        //     c = i;
        //     int k = 0;
        //     int s = v. size();
        //     while(r <= rows -1 && c <= cols -1 && k <= s-1){
        //         mat[r][c] = v[k];
        //         r++;c++;k++;
        //     }
        // }


        // for(int i = 0 ; i < rows; i++){
        //     vector<int> v; 
        //     int r = i;
        //     int c = 0;

        //     while(r <= rows-1 && c <=  cols-1){
        //         v.push_back(mat[r][c]);
        //         r++;c++;
        //     }

        //     sort(v.begin(),v.end());
        //     r = i;
        //     c = 0;
        //     int k = 0;
        //     int s = v. size();
        //     while(r <= rows -1 && c <= cols -1 && k <= s-1){
        //         mat[r][c] = v[k];
        //         r++;c++;k++;
        //     }
        // }
        // return mat;


        // remeber i-j and i+j trik for diagonal traversal always

        unordered_map<int, vector<int>> mp;

        for(int r = 0 ; r < mat.size();r++){
            for(int c = 0; c < mat[0].size();c++){
                mp[r-c].push_back(mat[r][c]);
            }
        }

        for(auto& f : mp) sort(f.second.begin(),f.second.end());

        for(int i = mat.size()-1 ; i >= 0 ;i--){
            for(int j = mat[0].size()-1; j >=0 ;j--){
                mat[i][j] = mp[i-j].back();
                mp[i-j].pop_back();
            }
        }

        return mat;
    }
};