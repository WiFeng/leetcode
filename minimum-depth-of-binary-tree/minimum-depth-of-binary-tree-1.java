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

        int leftMinDepth  = 0, rightMinDepth = 0;
        int minDepth = 1;
        if (root.left != null && root.right != null) {
            leftMinDepth = minDepth(root.left);
            rightMinDepth = minDepth(root.right);
            minDepth = 1 + Math.min(leftMinDepth, rightMinDepth);
        } else if (root.left != null) {
            minDepth = 1 + minDepth(root.left);
        } else if (root.right != null) {
            minDepth = 1 + minDepth(root.right);
        }

        return minDepth;
    }
}