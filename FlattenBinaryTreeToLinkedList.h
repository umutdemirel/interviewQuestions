//
//  FlattenBinaryTreeToLinkedList.h
//  
//
//  https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
//

#ifndef FlattenBinaryTreeToLinkedList_h
#define FlattenBinaryTreeToLinkedList_h

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
    TreeNode* flattenRec(TreeNode* node) {
        if (node->left != NULL)
        {
            TreeNode* tempRight = new TreeNode(-1);
            tempRight->right = node->right;
            
            TreeNode* tempLeft = new TreeNode(-1);
            tempLeft->right = node->left;
            node->left = NULL;
            
            node->right = flattenRec(tempLeft->right);
            if (tempRight->right != NULL)
            {
                TreeNode* iterator = node;
                while(iterator->right != NULL)
                {
                    iterator = iterator->right;
                }
                iterator->right = flattenRec(tempRight->right);
            }
        }
        else
        {
            if (node->right != NULL)
            {
                node->right = flattenRec(node->right);
            }
        }
        return node;
    }
    
    void flatten(TreeNode* root) {
        if (root == NULL)
        {
            return;
        }
        
        root = flattenRec(root);
        
        return;
    }
};

#endif /* FlattenBinaryTreeToLinkedList_h */
