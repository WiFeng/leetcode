bool isValid(char **board, int row, int col, char c) {
    int regionRow = (row/3)*3;
    int regionCol = (col/3)*3;
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == c) {
            return false;
        }
        if (board[i][col] == c) {
            return false;
        }
        if (board[regionRow + i/3][regionCol + i%3] == c) {
            return false;
        }
    }
    return true;
}

bool solve(char **board, int boardSize, int* boardColSize, int row, int col) {
    for (; row < boardSize; row++, col = 0) {
        for (; col < *boardColSize; col++) {
            if (board[row][col] != '.') {
                continue;
            }
            for (char c = '1'; c <= '9'; c++) {
                if (!isValid(board, row, col, c)) {
                    continue;
                }
                board[row][col] = c;
                if (solve(board, boardSize,  boardColSize, row, col)) {
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

    solve(board, boardSize, boardColSize, 0, 0);
}