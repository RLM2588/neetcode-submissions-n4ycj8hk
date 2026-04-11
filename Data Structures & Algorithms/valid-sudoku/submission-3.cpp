class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int columns[9] = {0};
        int quadro[9] = {0};
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') continue;

                int num = 1 << (board[i][j] - '1');
                if ((rows[i] & num) || (columns[j] & num) || (quadro[(i / 3) * 3 + (j / 3 )] & num)){
                    return false;
                }

                rows[i] |= num;
                columns[j] |= num;
                quadro[(i / 3) * 3 + (j / 3)] |= num;
            }
        }
        return true;
    }
};
