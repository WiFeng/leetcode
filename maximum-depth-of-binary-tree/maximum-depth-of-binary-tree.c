/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root){
    int r = 0;

    if (root == NULL) {
        return r;
    }

    int ld = maxDepth(root->left);
    int rd = maxDepth(root->right);
    if (ld > rd) {
        r = ld + 1;
    } else {
        r = rd + 1;
    }
    return r;
}
