//
//  HouseRobberIII.h
//  
//
//  https://leetcode.com/problems/house-robber-iii/description/
//

#ifndef HouseRobberIII_h
#define HouseRobberIII_h

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
    int robRec(TreeNode* node, bool included, int& currentMax) {
        int tempValue1 = 0;
        int tempValue2 = 0;
        int tempValue3 = 0;
        if (included) {
            tempValue1 += node->val;
            if (node->left != NULL) {
                tempValue1 += robRec(node->left, false, currentMax);
            }
            if (node->right != NULL) {
                tempValue1 += robRec(node->right, false, currentMax);
            }
            
            if (node->left != NULL) {
                tempValue2 += robRec(node->left, true, currentMax);
            }
            if (node->right != NULL) {
                tempValue2 += robRec(node->right, true, currentMax);
            }
        } else {
            if (node->left != NULL) {
                tempValue3 += robRec(node->left, true, currentMax);
            }
            if (node->right != NULL) {
                tempValue3 += robRec(node->right, true, currentMax);
            }
        }
        
        int currentValue = max(max(tempValue1, tempValue2), tempValue3);
        currentMax = max(currentMax, currentValue);
        
        return currentValue;
    }
    
    int rob(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        int currentMax = INT_MIN;
        
        int tempMax = robRec(root, true, currentMax);
        
        return max(tempMax, currentMax);
    }
};

#endif /* HouseRobberIII_h */
