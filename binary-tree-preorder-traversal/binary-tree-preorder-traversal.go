/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func preorderTraversal(root *TreeNode) []int {
    if root == nil {
        return nil
    }

    ri1 := preorderTraversal(root.Left)
    ri2 := preorderTraversal(root.Right)

    r := make([]int, 0, len(ri1) + len(ri2) + 1)
    r = append(r, root.Val)
    r = append(r, ri1...)
    r = append(r, ri2...)

    return r
}
