/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func preorder(root *Node) []int {
    r := make([]int, 0, 10)

    if root == nil {
        return nil
    }

    r = append(r, root.Val)

    for _, v := range root.Children { 
        t := preorder(v)
        r = append(r, t...)
    }

    return r
}
