class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        int n = buildings.length;
        List<List<Integer>> output = new ArrayList<List<Integer>>();

        // The base case
        if (n == 0) return output;
        if (n == 1) {
            int xStart = buildings[0][0];
            int xEnd = buildings[0][1];
            int y = buildings[0][2];

            output.add(new ArrayList<>(){{add(xStart); add(y);}});
            output.add(new ArrayList<>(){{add(xEnd); add(0);}});
            // output.add(new int[]{xStart, y});
            // output.add(new int[]{xEnd, 0});
            return output;
        }

        // If there is more than one buildings,
        // recursively divide the input into two subproblems.
        List<List<Integer>> leftSkyline, rightSkyline;
        leftSkyline = getSkyline(Arrays.copyOfRange(buildings, 0, n / 2));
        rightSkyline = getSkyline(Arrays.copyOfRange(buildings, n / 2 , n));

        // Merge the results of subprolems together.
        return mergeSkyline(leftSkyline, rightSkyline);
    }

    public List<List<Integer>> mergeSkyline(List<List<Integer>> left, List<List<Integer>> right) {
        int nL = left.size(), nR = right.size();
        int pL = 0, pR = 0;
        int currY = 0, leftY = 0, rightY = 0;
        int x, maxY;

        List<List<Integer>> output = new ArrayList<List<Integer>>();
        while (pL < nL &&  pR < nR) {
            List<Integer> pointL = left.get(pL);
            List<Integer> pointR = right.get(pR);

            // pick up the smallest x
            if (pointL.get(0) < pointR.get(0)) {
                x = pointL.get(0);
                leftY = pointL.get(1);
                pL++;
            } else {
                x = pointR.get(0);
                rightY = pointR.get(1);
                pR++;
            }

            // max height (i.e y ) between both skylines
            maxY = Math.max(leftY, rightY);
            // update output if there is a skyline change
            if (currY != maxY) {
                updateOutput(output, x, maxY);
                currY = maxY;
            }

        }

        // there is only left skyline
        appendSkyline(output, left, pL, nL, currY);

        // there is only right skyline
        appendSkyline(output, right, pR, nR, currY);

        return output;
    }

    /**
     * Update the  final output with the new element.
     * 
     * @param output
     * @param x
     * @param y
     */
    public void updateOutput(List<List<Integer>> output, int x, int y) {
        // if skyline change is not vertical -  add the new  point
        if (output.isEmpty() || output.get(output.size() - 1).get(0) != x) {
            output.add(new ArrayList<>(){{add(x); add(y);}});
        } else {
            // if skyline change is vertical - update the last point
            output.get(output.size() - 1).set(1, y);
        }
    }

    public void appendSkyline(List<List<Integer>> output, List<List<Integer>> skyline, int p, int n, int currY) {
        while (p < n) {
            List<Integer> point  = skyline.get(p);
            int x = point.get(0);
            int y = point.get(1);
            p++;

            // update point
            // if there is a skyline change
            if (currY != y) {
                updateOutput(output, x, y);
                currY = y;
            }
        }
    }
}