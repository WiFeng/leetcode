/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;

    if (root == NULL) {
        return NULL;
    }

    int rs1 = 0, rs2 = 0;
    int *ri1 = preorderTraversal(root->left, &rs1);
    int *ri2 = preorderTraversal(root->right, &rs2);

    *returnSize = rs1 + rs2 + 1;

    int *ri = malloc(sizeof(int) * (*returnSize));
    ri[0] = root->val;

    if (rs1 > 0  && ri1 != NULL) {
        memcpy(ri + 1, ri1, sizeof(int) * rs1);
        free(ri1);
    }

    if (rs2 > 0 && ri2 != NULL) {
       memcpy(ri + 1 + rs1, ri2, sizeof(int) * rs2);
       free(ri2);
    }

    return ri;
}
