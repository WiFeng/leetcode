class Solution {
    public int trap(int[] height) {
        int result = 0;
        Stack<Integer> S = new Stack<>();
        for (int i = 0; i < height.length; i++) {
            while (!S.empty() && height[i] > height[S.peek()]) {
                int top1 = S.peek();
                S.pop();

                if (S.empty()) {
                    break;
                }

                int top2 = S.peek();
                int w = i - top2 - 1;
                int h = Math.min(height[i], height[top2]) - height[top1];
                result += w * h;
            }
            S.push(i);
        }

        return result;
    }
}