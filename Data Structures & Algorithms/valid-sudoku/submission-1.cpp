class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j;
        vector<int> row, col, box;
        char c;

        for (i = 0; i < 9; i++) {
            row.assign(9, 0);
            col.assign(9, 0);
            box.assign(9, 0);

            for (j = 0; j < 9; j++) {
                if (board[i][j] != '.' && row[board[i][j] - '1']++)
                    return false;

                if (board[j][i] != '.' && col[board[j][i] - '1']++)
                    return false;

                c = board[3*(i/3) + j/3][3*(i%3) + j%3];
                if (c != '.' && box[c - '1']++)
                    return false; 
            }
        }

        return true;
    }
};
