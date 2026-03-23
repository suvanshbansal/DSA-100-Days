/*
Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
*/
/**
 * Definition for a binary tree node.
 */
#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    // Base case: root is NULL or value found
    if (root == NULL || root->val == val) {
        return root;
    }

    // If value is smaller, search in left subtree
    if (val < root->val) {
        return searchBST(root->left, val);
    }

    // If value is greater, search in right subtree
    return searchBST(root->right, val);
}

//iterative approach code
/*
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    while (root != NULL) {
        if (root->val == val) {
            return root;
        } else if (val < root->val) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL;
}
    */