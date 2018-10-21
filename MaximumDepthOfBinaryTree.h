//
//  MaximumDepthOfBinaryTree.h
//  
//
//  Created by umut demirel on 21.10.2018.
//

#ifndef MaximumDepthOfBinaryTree_h
#define MaximumDepthOfBinaryTree_h

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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        vector<TreeNode*> tempQueue;
        tempQueue.push_back(root);
        
        int currentDepth = 0;
        while(!tempQueue.empty()) {
            currentDepth++;
            int tempSize= tempQueue.size();
            for (int i = 0; i < tempSize; i++) {
                TreeNode* tempNode = tempQueue[0];
                if (tempNode->left != NULL) {
                    tempQueue.push_back(tempNode->left);
                }
                if (tempNode->right != NULL) {
                    tempQueue.push_back(tempNode->right);
                }
                tempQueue.erase(tempQueue.begin());
            }
        }
        return currentDepth;
    }
};

#endif /* MaximumDepthOfBinaryTree_h */
