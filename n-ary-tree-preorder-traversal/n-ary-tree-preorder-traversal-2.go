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
        return r
    }

    stack := make([]*Node, 0, 10000)
    stack = append(stack, root)

    // for _, v := range stack {
    for i := 0; i < len(stack); i++ {
        v := stack[i]
        r = append(r, v.Val)

        // t := stack[i+1:len(stack)]
        t := make([]*Node, len(stack) - i - 1)
        copy(t, stack[i+1:len(stack)])

        stack = stack[0:i+1]
        for _, vv := range v.Children {
            stack = append(stack, vv)
        }
        stack = append(stack, t...)
    }

    return r
}
