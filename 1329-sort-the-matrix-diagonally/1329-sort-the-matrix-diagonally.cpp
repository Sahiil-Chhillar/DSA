class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        for(int i = 0 ; i < cols ; i++){
            vector<int> v;
            int r = 0;
            int c = i;
            while(r <= rows-1 && c <= cols-1){
                v.push_back(mat[r][c]);
                r++;c++;
            }

            sort(v.begin(),v.end());
            r = 0;
            c = i;
            int k = 0;
            int s = v. size();
            while(r <= rows -1 && c <= cols -1 && k <= s-1){
                mat[r][c] = v[k];
                r++;c++;k++;
            }
        }


        for(int i = 0 ; i < rows; i++){
            vector<int> v; 
            int r = i;
            int c = 0;

            while(r <= rows-1 && c <=  cols-1){
                v.push_back(mat[r][c]);
                r++;c++;
            }

            sort(v.begin(),v.end());
            r = i;
            c = 0;
            int k = 0;
            int s = v. size();
            while(r <= rows -1 && c <= cols -1 && k <= s-1){
                mat[r][c] = v[k];
                r++;c++;k++;
            }
        }
        return mat;
    }
};