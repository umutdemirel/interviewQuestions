//
//  SymmetricTree.h
//  
//
//  https://leetcode.com/problems/symmetric-tree/description/
//

#ifndef SymmetricTree_h
#define SymmetricTree_h

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <queue>

using namespace std;

class Solution {
    
public:
    bool checkRec(TreeNode* left, TreeNode* right)
    {
        if (left == NULL && right == NULL)
        {
            return true;
        }
        else if (left == NULL && right != NULL)
        {
            return false;
        }
        else if (left != NULL && right == NULL)
        {
            return false;
        }
        else
        {
            if (left->val == right->val)
            {
                return checkRec(left->left, right->right) && checkRec(left->right, right->left);
            }
            else
            {
                return false;
            }
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return true;
        }
        
        return checkRec(root->left, root->right);
    }
};

#endif /* SymmetricTree_h */
