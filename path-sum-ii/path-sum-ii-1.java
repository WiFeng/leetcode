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

    private List<List<Integer>> result = new ArrayList<>();

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if (root == null) {
            return result;
        }

        List<Integer> list = new LinkedList<>();
        recursive(root, list, sum);
        return result;
    }

    private void recursive(TreeNode root, List<Integer> list, int sum) {
        list.add(root.val);

        if (root.left == null && root.right == null) {
            if (sum == root.val) {
                // ans
                ArrayList<Integer> ans = new ArrayList<>();
                for (Integer item : list) {
                    ans.add(item);
                }
                result.add(ans);
            }
            return;
        }

        if (root.left != null) {
            recursive(root.left, list, sum - root.val);
            //list.remove();
            list.remove(list.size()-1);
        }

        if (root.right != null) {
            recursive(root.right, list, sum - root.val);
            //list.remove();
            list.remove(list.size()-1);
        }
    }
}