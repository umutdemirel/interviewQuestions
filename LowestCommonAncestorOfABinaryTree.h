//
//  LowestCommonAncestorOfABinaryTree.h
//  
//
//  https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
//

#ifndef LowestCommonAncestorOfABinaryTree_h
#define LowestCommonAncestorOfABinaryTree_h

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
    bool isInside(TreeNode* node, TreeNode* root) {
        if (root == NULL) {
            return false;
        }
        else if (node->val == root->val) {
            return true;
        } else {
            return isInside(node, root->left) || isInside(node, root->right);
        }
    }
    
    TreeNode* lcaRec(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        
        bool pIsInLeft = isInside(p, root->left);
        bool qIsInLeft = isInside(q, root->left);
        
        if (pIsInLeft != qIsInLeft) {
            cout << "found : " << root->val << endl;
            return root;
        } else {
            if (pIsInLeft) {
                return lcaRec(root->left, p, q);
            } else {
                return lcaRec(root->right, p, q);
            }
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lcaRec(root, p, q);
    }
};

#endif /* LowestCommonAncestorOfABinaryTree_h */
