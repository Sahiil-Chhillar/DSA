class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        int sRow = 0;
        int sCol = 0;
        int eRow = matrix.size()-1;
        int eCol = matrix[0].size()-1;

        while(sRow <= eRow && sCol <= eCol){
            for(int i = sCol; i <= eCol;i++){
                result.push_back(matrix[sRow][i]);
            }
            sRow++;

            for(int i = sRow;i <= eRow ; i++){
                result.push_back(matrix[i][eCol]);
            }
            eCol--;


            // in case of odd length matrix if any of two are on same row or col then one should be stored
            if(sRow <= eRow){
                for(int i = eCol ; i >= sCol ;i--){
                result.push_back(matrix[eRow][i]);
                }
                eRow--;
            }

            if(sCol <= eCol){
                for(int i = eRow; i >= sRow ; i--){
                result.push_back(matrix[i][sCol]);
                }
                sCol++;
            }
        }

        return result;
    }
};