//
//  SubtreeOfAnotherTree.h
//  
//
//  https://leetcode.com/problems/subtree-of-another-tree/description/
//

#ifndef SubtreeOfAnotherTree_h
#define SubtreeOfAnotherTree_h

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
    bool checkRec(TreeNode* s, TreeNode* t) {
        if (s != NULL && t != NULL && s->val == t->val) {
            return checkRec(s->left, t->left) && checkRec(s->right, t->right);
        } else if (s == NULL && t == NULL) {
            return true;
        } else {
            return false;
        }
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        
        if (s == NULL && t == NULL) {
            return true;
        } else if (s == NULL) {
            return false;
        } else {
            bool result = false;
            if (s->val == t->val) {
                result = checkRec(s->left, t->left) && checkRec(s->right, t->right);
            }
            
            return result || isSubtree(s->left, t) || isSubtree(s->right, t);
        }
    }
};

#endif /* SubtreeOfAnotherTree_h */
