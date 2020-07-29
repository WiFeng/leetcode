class Solution {
    private int[][] points;

    public int[][] kClosest(int[][] points, int K) {
        this.points = points;
        work(0, points.length - 1, K);
        return Arrays.copyOfRange(points, 0, K);
    }

    public void work(int i, int j, int K) {
        if (i >= j) return;
        
        int oi = i, oj = j;
        int pivotIndex = ThreadLocalRandom.current().nextInt(i, j); // 0
        int pivotVal = dist(pivotIndex);

        while (i < j) {
            while (i < j && dist(i) < pivotVal) i++; // i = 1
            while (i < j && dist(j) > pivotVal) j--;
            swap(i, j);
            if (dist(i) == pivotVal && dist(j) == pivotVal){
                break;
            }
        }

        if (i - oi + 1 >= K) {
            work(oi, i, K);
        } else {
            work(i + 1, oj, K - (i - oi + 1));
        }

    }

    public void swap(int i, int j) {
        int t0 = points[i][0], t1 = points[i][1];
        points[i][0] = points[j][0];
        points[i][1] = points[j][1];
        points[j][0] = t0;
        points[j][1] = t1;
    }

    public int dist(int i) {
        return points[i][0] * points[i][0] + points[i][1] * points[i][1];
    }
}