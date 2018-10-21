//
//  BinaryTreeMaximumPathSum.h
//  
//
//  https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
//

#ifndef BinaryTreeMaximumPathSum_h
#define BinaryTreeMaximumPathSum_h

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
    int maxPathSumRec(TreeNode* node, int &currentSum) {
        int leftSum;
        if (node->left != NULL) {
            leftSum = maxPathSumRec(node->left, currentSum);
        }
        else
        {
            leftSum = 0;
        }
        
        int rightSum;
        if (node->right != NULL) {
            rightSum = maxPathSumRec(node->right, currentSum);
        }
        else
        {
            rightSum = 0;
        }
        
        int tempMax = INT_MIN;
        if (node->val > tempMax) {
            tempMax = node->val;
        }
        
        if (node->left != NULL) {
            if (node->val + leftSum > tempMax) {
                tempMax = node->val + leftSum;
            }
        }
        
        if (node->right != NULL) {
            if (node->val + rightSum > tempMax) {
                tempMax = node->val + rightSum;
            }
        }
        if (tempMax > currentSum) {
            currentSum = tempMax;
        }
        
        int totalSum = node->val;
        if (node->left != NULL) {
            totalSum += leftSum;
        }
        if (node->right != NULL) {
            totalSum += rightSum;
        }
        if (totalSum > currentSum) {
            currentSum = totalSum;
        }
        
        return tempMax;
    }
    
    int maxPathSum(TreeNode* root) {
        int currentMax = root->val;
        
        int tempSum = maxPathSumRec(root, currentMax);
        
        return currentMax;
    }
};

#endif /* BinaryTreeMaximumPathSum_h */
