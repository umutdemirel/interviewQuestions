//
//  ConvertBSTToGreaterTree.h
//  
//
//  https://leetcode.com/problems/convert-bst-to-greater-tree/description/
//

#ifndef ConvertBSTToGreaterTree_h
#define ConvertBSTToGreaterTree_h

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
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        
        unordered_map<TreeNode*, bool> visited;
        
        int currentTotal = 0;
        
        stack<TreeNode*> myStack;
        
        myStack.push(root);
        
        while (!myStack.empty()) {
            TreeNode* current = myStack.top();
            if (visited.find(current) == visited.end()) {
                visited[current] = true;
                if (current->right != NULL) {
                    myStack.push(current->right);
                }
            } else {
                myStack.pop();
                currentTotal += current->val;
                current->val = currentTotal;
                if (current->left != NULL) {
                    myStack.push(current->left);
                }
            }
        }
        
        return root;
    }
};

#endif /* ConvertBSTToGreaterTree_h */
