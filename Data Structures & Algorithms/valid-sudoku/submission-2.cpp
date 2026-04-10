class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // ploho
        
        for(auto& i: board) {
            unordered_map<char, int> hmap;
            for(char j: i) {
                if(j == '.') continue;
                if (hmap[j] != 0) return false;
                ++hmap[j];
            }
        }

        for(int i = 0; i < 9; ++i) {
            unordered_map<char, int> hmap;
            for(int j = 0; j < 9; ++j) {
                if(board[j][i] == '.') continue;
                if (hmap[board[j][i]] != 0) return false;
                ++hmap[board[j][i]];
            }
        }

        for(int a = 0; a < 3; ++a) {
            for(int b = 0; b < 3; ++b) {
                unordered_map<char, int> hmap;
                for(int c = 0; c < 3; ++c) {
                    for(int d = 0; d < 3; ++d) {
                        char ca = board[3*a + c][3*b + d];
                        if(ca == '.') continue;
                        if (hmap[ca] != 0) return false;
                        ++hmap[ca];
                    }
                }
            }
        }
        return true;
    }
};
