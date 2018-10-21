//
//  BinaryTreeLevelOrderTraversal.h
//  
//
//  https://leetcode.com/problems/binary-tree-level-order-traversal/description/
//

#ifndef BinaryTreeLevelOrderTraversal_h
#define BinaryTreeLevelOrderTraversal_h

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if (root == NULL)
        {
            return result;
        }
        
        vector<TreeNode*> tempQueue;
        tempQueue.push_back(root);
        
        while(!tempQueue.empty()) {
            vector<int> tempResult;
            
            for (int i = 0; i < tempQueue.size(); i++)
            {
                tempResult.push_back(tempQueue[i]->val);
            }
            
            result.push_back(tempResult);
            
            int tempQueueSize = tempQueue.size();
            for (int i = 0; i < tempQueueSize; i++)
            {
                TreeNode* tempNode = tempQueue[0];
                
                if (tempNode->left != NULL)
                {
                    tempQueue.push_back(tempNode->left);
                }
                if (tempNode->right != NULL)
                {
                    tempQueue.push_back(tempNode->right);
                }
                tempQueue.erase(tempQueue.begin());
            }
        }
        
        return result;
    }
};

#endif /* BinaryTreeLevelOrderTraversal_h */
