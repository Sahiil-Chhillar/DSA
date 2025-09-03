class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++) {
            if (target >= matrix[i][0] && target <= matrix[i][cols - 1]) {
                int st = 0;
                int end = cols-1;

                while(st <= end){
                    int mid = st + (end-st)/2;

                    if(matrix[i][mid] == target) return true;

                    else if(matrix[i][mid] < target) st = mid + 1;
                    else end = mid -1;
                }
                return false;
            }
        }
        return false;
    }
};