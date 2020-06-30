class Solution {
    int rows[];
    int hills[];
    int dales[];
    int n;

    List<List<String>> output = new ArrayList<>();
    int queens[];

    private boolean isNotUnderAttack(int row, int col) {
        int res = rows[col] + hills[row - col + 2 * n] + dales[row + col];
        if (res == 0) {
            return true;
        }
        return false;
    }

    private void addSolution() {
        List<String> solution = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int col = queens[i];
            StringBuffer buffer = new StringBuffer();
            for (int j = 0; j < col; j++) {
                buffer.append(".");
            }
            buffer.append("Q");
            for (int j = col + 1; j < n; j++) {
                buffer.append(".");
            }

            solution.add(buffer.toString());
        }
        output.add(solution);
    }

    private void placeQueen(int row, int col) {
        queens[row] = col;
        rows[col] = 1;
        hills[row - col + 2 * n] = 1;
        dales[row + col] = 1;
    }

    private void removeQueen(int row, int col) {
        queens[row] = 0;
        rows[col] = 0;
        hills[row - col + 2 * n] = 0;
        dales[row + col] = 0;
    }

    private void backtrace(int row) {
        for (int col = 0; col < n; col++) {
            if (!isNotUnderAttack(row, col)) {
                continue;
            }
            placeQueen(row, col);
            if (row + 1 == n) {
                addSolution();
            } else {
                backtrace(row + 1);
            }
            removeQueen(row, col);
        }
    }

    public List<List<String>> solveNQueens(int n) {
        this.n = n;
        this.rows = new int[n];
        this.hills = new int[n * 4];
        this.dales = new int[n * 2];
        this.queens = new int[n];

        backtrace(0);

        return output;
        
    }
}