/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isValidBST(root *TreeNode) bool {
    if root == nil {
        return true
    }
    _, _, valid := checkNode(root)
    return valid
}

func checkNode(root *TreeNode) (minVal int, maxVal int, valid bool) {
   
    minVal = root.Val
    maxVal = root.Val
    valid = true

    if root.Left != nil {
        leftMinVal, leftMaxVal, leftValid := checkNode(root.Left)
        if leftMaxVal < root.Val && leftValid {
            minVal = leftMinVal
            valid = true
        } else {
            valid = false
            return
        }
    }

    if root.Right != nil {
        rightMinVal, rightMaxVal, rightValid := checkNode(root.Right)
        if rightMinVal > root.Val && rightValid {
            maxVal = rightMaxVal
            valid = true
        } else {
            valid = false
            return
        }
    }
    
    return
}
