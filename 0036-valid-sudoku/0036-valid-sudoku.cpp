// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         for(int i = 0 ; i < board.size();i++){
//             set<char> st;
//             for(int j = 0; j < board[0].size();j++){
//                 if(board[i][j] == '.') continue;
//                 if(st.find(board[i][j]) != st.end()){
//                     return false;
//                 }
//                 st.insert(board[i][j]);
//             }
//         }

//         for(int i = 0 ; i < board[0].size();i++){
//             set<char> st;
//             for(int j = 0; j < board.size();j++){
//                 if(board[j][i] == '.') continue;
//                 if(st.find(board[j][i]) != st.end()){
//                     return false;
//                 }
//                 st.insert(board[j][i]);
//             }
//         }

//         for(int i = 0 ; i < board.size();i+=3){
//             for(int c = 0; c < board[0].size();c+=3){
//                 set<char> st;
//                 for(int j = i; j < i + 3 ; j++){
//                     for(int k = c ;k < c + 3;k++){
//                         if(board[j][k] == '.') continue;
//                         if(st.find(board[j][k]) != st.end()) return false;
//                         st.insert(board[j][k]);
//                     }
//                 }
//             }  
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    if (rows[i][num] || cols[j][num] || boxes[boxIndex][num]) return false;
                    rows[i][num] = cols[j][num] = boxes[boxIndex][num] = true;
                }
            }
        }
        return true;
    }
};