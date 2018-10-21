//
//  ConstructBinaryTreeFromPreorderAndInorderTraversal.h
//  
//
//  https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
//

#ifndef ConstructBinaryTreeFromPreorderAndInorderTraversal_h
#define ConstructBinaryTreeFromPreorderAndInorderTraversal_h

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
    TreeNode* buildTreeRec(vector<int>& preorder, vector<int>& inorder, int leftEnd, int root, int rightEnd) {
        int newRoot;
        for (int i = leftEnd; i < rightEnd + 1; i++) {
            if (inorder[i] == preorder[root]) {
                newRoot = i;
                break;
            }
        }
        
        cout << leftEnd << " " << newRoot << " " << rightEnd << endl;
        
        TreeNode* newTree = new TreeNode(inorder[newRoot]);
        if (newRoot - leftEnd > 0) {
            newTree->left = buildTreeRec(preorder, inorder, leftEnd, root+1, newRoot - 1);
        }
        if (rightEnd - newRoot > 0) {
            newTree->right = buildTreeRec(preorder, inorder, newRoot + 1, root + newRoot - leftEnd + 1, rightEnd);
        }
        
        return newTree;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return NULL;
        }
        return buildTreeRec(preorder, inorder, 0, 0, preorder.size() - 1);
    }
};

#endif /* ConstructBinaryTreeFromPreorderAndInorderTraversal_h */
