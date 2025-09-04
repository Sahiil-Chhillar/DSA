class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m = image.size();
        int n = image[0].size();
        for(int r = 0 ; r < m;r++){
            int st = 0;
            int end = n - 1;
            while(st<end){
                swap(image[r][st],image[r][end]);
                st++;
                end--;
            }
        }

        for(int r = 0 ; r < m;r++){
            for(int c = 0 ; c < n ;c++){
                image[r][c] = !image[r][c];
            }
        }

        return image;
    }
};