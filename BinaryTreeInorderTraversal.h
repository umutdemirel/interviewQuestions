//
//  BinaryTreeInorderTraversal.h
//  
//
//  https://leetcode.com/problems/binary-tree-inorder-traversal/description/
//

#ifndef BinaryTreeInorderTraversal_h
#define BinaryTreeInorderTraversal_h

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL)
        {
            return result;
        }
        
        vector<TreeNode*> stack;
        
        stack.push_back(root);
        
        while(stack.size() > 0)
        {
            TreeNode* temp = stack[stack.size() - 1];
            if (temp->left != NULL && temp->left->val != INT_MAX)
            {
                stack.push_back(temp->left);
            }
            else
            {
                result.push_back(temp->val);
                temp->val = INT_MAX;
                stack.pop_back();
                if (temp->right != NULL && temp->right->val != INT_MAX)
                {
                    stack.push_back(temp->right);
                }
            }
        }
        
        
        return result;
    }
};

#endif /* BinaryTreeInorderTraversal_h */
