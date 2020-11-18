int rowhash[9][9], colhash[9][9], blockhash[3][3][9];

        bool Sudoku(vector<vector<char> > &board, int position) {
            if (position >= 9*9) {
                return true;
            }
            int row = position / 9, col = position % 9;
            if (board[row][col] != '.') {
                return Sudoku(board, position + 1);
            }
            for (int num = 0; num < 9; num++) {
                if (rowhash[row][num] != 1 && colhash[col][num] != 1 && blockhash[row / 3][col / 3][num] != 1) {
                    // Include num in the solution 
                    board[row][col] = '1' + num;
                    rowhash[row][num] = 1;
                    colhash[col][num] = 1;
                    blockhash[row / 3][col / 3][num] = 1;
                    if (Sudoku(board, position + 1)) return true;
                    // Reset
                    board[row][col] = '.';
                    rowhash[row][num] = 0;
                    colhash[col][num] = 0;
                    blockhash[row / 3][col / 3][num] = 0;
                }
            }
            return false;
        }
void Solution::solveSudoku(vector<vector<char> > &A) {
    memset(rowhash, 0, sizeof(rowhash));
            memset(colhash, 0, sizeof(colhash));
            memset(blockhash, 0, sizeof(blockhash));
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (A[i][j] != '.') {
                        int num = A[i][j] - '1';
                        rowhash[i][num] = 1;
                        colhash[j][num] = 1;
                        blockhash[i / 3][j / 3][num] = 1;
                    }
                }
            }
            Sudoku(A, 0);
        }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
