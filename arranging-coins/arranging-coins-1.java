class Solution {
    public int arrangeCoins(int n) {
        long m = 0;

        int i;
        for (i = 1; n > m; i++) {
            m += i;
        }

        if (n < 1) {
            return 0;
        } else if (m == n) {
            return i - 1;
        } else {
            return i - 2;
        }
    }
}