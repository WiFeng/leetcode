/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isValidBST(struct TreeNode* root){
    if (root == NULL) {
        return true;
    }

    int minVal, maxVal; bool valid;
    checkNode(root, &minVal, &maxVal, &valid);
    return valid;
}

void checkNode(struct TreeNode* root, int* minVal, int* maxVal, bool* valid) {
    // root must be not null
    *minVal = root->val;
    *maxVal = root->val;
    *valid = true;

    int leftMinVal, leftMaxVal; bool leftValid = true;
    int rightMinVal, rightMaxVal; bool rightValid = true;

    // max / less than
    // the max value of the left subtree less than the node's key
    if (root->left != NULL) {
        checkNode(root->left, &leftMinVal, &leftMaxVal, &leftValid);
        if (leftMaxVal < root->val && leftValid) {
            *minVal = leftMinVal;
            *valid = true;
        } else {
            *valid = false;
            return;
        }
    }

    // min / greater than
    // the min value of the right subtree greater than the node's key
    if (root->right != NULL) {
        checkNode(root->right, &rightMinVal,  &rightMaxVal, &rightValid);
        if (rightMinVal > root->val && rightValid) {
            *maxVal = rightMaxVal;
            *valid = true;
        } else {
            *valid = false;
            return;
        }
    }
}
