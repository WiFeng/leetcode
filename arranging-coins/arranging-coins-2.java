class Solution {
    public int arrangeCoins(int n) {

        if (n < 1) {
            return 0;
        }
        
        int lo = 1, hi = n;
        long mid = 0;
        long sum = 0;

        while (lo + 1 < hi) {
            mid = lo + (hi - lo) / 2;
            sum = caculateSum(mid);
            if (sum > n) {
                hi = (int)mid;
            } else if (sum < n) {
                lo = (int)mid;
            } else {
                return (int)mid;
            }
        }

        if (caculateSum(hi) < n) {
            return hi;
        } else {
            return lo;
        }
    }

    private long caculateSum(long i) {
        long sum = (1 + i) * i / 2;
        return sum;
    }
}