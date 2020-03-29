/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

type Stack struct {
    Val *Node
    Next *Stack
}

func preorder(root *Node) []int {

    r := make([]int, 0, 10)

    if root == nil {
        return r
    }

    stack := &Stack{
        Val : root,
    }

    for v := stack; v != nil; v = v.Next {
        r = append(r, v.Val.Val)
        t := v.Next

        c := v
        for _, vv := range v.Val.Children {
            c.Next = &Stack{
                Val : vv,
            }
            c = c.Next
        }
        c.Next = t
    }

    return r
}
