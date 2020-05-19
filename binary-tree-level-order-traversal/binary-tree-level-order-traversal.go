/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
    if root == nil {
        return nil
    }
    
    var result = make([][]int, 0, 10)
    var queue = make([]*TreeNode, 1, 10)
    queue[0] = root

    for len(queue) > 0 {
        len := len(queue)
        tmp := make([]int, len)
        i := 0
        for j := len; j > 0; j-- {
            node := queue[0]
            queue = queue[1:]

            tmp[i] = node.Val
            i++

            if node.Left != nil {
                queue = append(queue, node.Left)
            }
            if node.Right != nil {
                queue = append(queue, node.Right)
            }
        }
        result = append(result, tmp)
    }
    return result
}
