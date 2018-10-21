//
//  ValidateBinarySearchTree.h
//  
//
//  https://leetcode.com/problems/validate-binary-search-tree/description/
//

#ifndef ValidateBinarySearchTree_h
#define ValidateBinarySearchTree_h

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
    void checkValidRec(TreeNode* node, bool &found, long currentMin, long currentMax)
    {
        if (found == false)
        {
            return;
        }
        if (node->left != NULL)
        {
            //cout << "comparing : " << node->left->val << " with " << node->val << " and " << val << endl;
            if (node->left->val >= node->val || node->left->val >= currentMax || node->left->val <= currentMin)
            {
                found = false;
                return;
            }
            else
            {
                checkValidRec(node->left, found, currentMin, min(currentMax, (long)node->val));
            }
        }
        if (node->right != NULL)
        {
            //cout << "comparing : " << node->right->val << " with " << node->val << " and " << val << endl;
            if (node->right->val <= node->val || node->right->val >= currentMax || node->right->val <= currentMin)
            {
                found = false;
                return;
            }
            else
            {
                checkValidRec(node->right, found, max(currentMin, (long)node->val), currentMax);
            }
        }
    }
    
    bool isValidBST(TreeNode* root) {
        bool found = true;
        if (root == NULL)
        {
            return found;
        }
        checkValidRec(root, found, LONG_MIN, LONG_MAX);
        return found;
    }
};

#endif /* ValidateBinarySearchTree_h */
