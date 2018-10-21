//
//  InvertBinaryTree.h
//  
//
//  https://leetcode.com/problems/invert-binary-tree/description/
//

#ifndef InvertBinaryTree_h
#define InvertBinaryTree_h

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void invertRec(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
        invertRec(node->left);
        invertRec(node->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        invertRec(root);
        
        return root;
    }
};

#endif /* InvertBinaryTree_h */
