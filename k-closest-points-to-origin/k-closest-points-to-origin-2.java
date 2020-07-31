class Solution {

    int[][] points;

    public int[][] kClosest(int[][] points, int K) {
        this.points = points;
        work(0, points.length - 1, K);
        return Arrays.copyOfRange(points, 0, K);
    }

    private void work(int i, int j, int K) {
        if (i >= j) return;

        int oi = i, oj = j;
        int pivotIndex = ThreadLocalRandom.current().nextInt(i, j);
        int pivotVal = dist(pivotIndex);

        while (i < j) {
            while (i < j && dist(i) < pivotVal) i++;
            while (i < j && dist(j) > pivotVal) j--;
            
            if (dist(i) == pivotVal && dist(j) == pivotVal) {
                break;
            }

            swap(i, j);
        }

        if (i - oi + 1 >= K) {
            work(oi, j, K);
        } else {
            work(i+1, oj, K - (i - oi + 1));
        }
    }

    private int dist(int i) {
        return points[i][0] * points[i][0] + points[i][1] * points[i][1];
    }

    private void swap(int i, int j) {
        int t0 = points[i][0], t1 = points[i][1];
        points[i][0] = points[j][0];
        points[i][1] = points[j][1];
        points[j][0] = t0;
        points[j][1] = t1;
    }

    
}