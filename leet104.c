#include <stdlib.h>
#include <stdio.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
static int traverse(struct TreeNode* root, int depth) {
    if (root == NULL) {
        return depth;
    }
    int l = traverse(root->left, depth+1);
    int r = traverse(root->right, depth+1);
    if (l > r) {
        return l;
    } else {
        return r; 
    }
}
int maxDepth(struct TreeNode* root) {
    return traverse(root, 0);
}
