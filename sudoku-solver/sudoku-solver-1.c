bool isValid(char **board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == c) {
            return false;
        }
        if (board[i][col] == c) {
            return false;
        }
        if (board[(row/3)*3 + i/3][(col/3)*3 + i%3] == c) {
            return false;
        }
    }
    return true;
}

bool solve(char **board, int boardSize, int* boardColSize) {
    for (int row = 0; row < boardSize; row++) {
        for (int col = 0; col < *boardColSize; col++) {
            if (board[row][col] != '.') {
                continue;
            }
            for (char c = '1'; c <= '9'; c++) {
                if (!isValid(board, row, col, c)) {
                    continue;
                }
                board[row][col] = c;
                if (solve(board, boardSize,  boardColSize)) {
                    return true;
                }
                board[row][col] = '.';
            }
            return false;
        }
    }
    return true;
}

void solveSudoku(char** board, int boardSize, int* boardColSize){
    if (board == NULL || boardSize < 1) {
        return;
    }

    solve(board, boardSize, boardColSize);
}