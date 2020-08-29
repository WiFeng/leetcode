/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int minDepth(TreeNode root) {

        if (root == null) {
            return 0;
        }

        int minDepth = 0;
        Queue<Pair<TreeNode, Integer>> Q = new LinkedList<>();
        Q.add(new Pair<>(root, 1));

        while (!Q.isEmpty()) {
            Pair pair = Q.poll();
            TreeNode node = (TreeNode) pair.getKey();
            Integer level = (Integer) pair.getValue();
            if (node.left == null && node.right == null) {
                return level;
            }
            if (node.left != null) {
                Q.add(new Pair<>(node.left, level + 1));
            }
            if (node.right != null) {
                Q.add(new Pair<>(node.right, level + 1));
            }
        }

        return minDepth;
    }
}