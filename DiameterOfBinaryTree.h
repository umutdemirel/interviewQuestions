//
//  DiameterOfBinaryTree.h
//  
//
//  https://leetcode.com/problems/diameter-of-binary-tree/description/
//

#ifndef DiameterOfBinaryTree_h
#define DiameterOfBinaryTree_h

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
    int checkRec(TreeNode* node, int &maxLength) {
        if (node->left == NULL && node->right == NULL) {
            return 0;
        }
        
        int maxLeft = 0;
        if (node->left != NULL) {
            maxLeft = 1 + checkRec(node->left, maxLength);
        }
        
        int maxRight = 0;
        if (node->right != NULL) {
            maxRight = 1 + checkRec(node->right, maxLength);
        }
        
        if (maxLeft + maxRight > maxLength) {
            maxLength = maxLeft + maxRight;
        }
        
        return max(maxLeft, maxRight);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        int maxLength = 0;
        
        int length = checkRec(root, maxLength);
        
        return max(length, maxLength);
    }
};

#endif /* DiameterOfBinaryTree_h */
