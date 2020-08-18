class Solution {

    private Map<Integer, Integer> memo = new HashMap<>();
    
    public int superEggDrop(int K, int N) {
        return dp(K, N);
    }

    private int dp(int K, int N) {
        int key = N * 100 + K;
        if (memo.containsKey(key)) {
            return memo.get(key);
        }

        int ans;
        if (N == 0) {
            ans = 0;
        } else if (K == 1) {
            ans = N;
        } else {
            int lo = 1, hi = N;
            while (lo + 1 < hi) {
                int x = (lo + hi) / 2;
                int t1 = dp(K-1, x-1);
                int t2 = dp(K, N-x);

                if (t1 < t2) {
                    lo = x;
                } else if (t1 > t2) {
                    hi = x;
                } else {
                    lo = hi = x;
                }
            }

            ans = 1 + Math.min(Math.max(dp(K-1,lo-1), dp(K, N-lo)),
                                Math.max(dp(K-1, hi-1), dp(K, N-hi)));
        }

        memo.put(key, ans);

        return ans;
    }
}