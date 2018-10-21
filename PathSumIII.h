//
//  PathSumIII.h
//  
//
//  https://leetcode.com/problems/path-sum-iii/description/
//

#ifndef PathSumIII_h
#define PathSumIII_h

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
    void checkRec(TreeNode* currentNode, bool initial, int currentSum, int sum, int &total, unordered_map<TreeNode*, bool> &visited) {
        if (currentNode == NULL) {
            return;
        }
        
        if (initial) {
            if (visited.find(currentNode) == visited.end()) {
                visited[currentNode] = true;
            } else {
                return;
            }
        }
        
        currentSum += currentNode->val;
        
        if (currentSum == sum) {
            total++;
        }
        
        checkRec(currentNode->left, false, currentSum, sum, total, visited);
        checkRec(currentNode->left, true, 0, sum, total, visited);
        checkRec(currentNode->right, false, currentSum, sum, total, visited);
        checkRec(currentNode->right, true, 0, sum, total, visited);
    }
    
    int pathSum(TreeNode* root, int sum) {
        unordered_map<TreeNode*, bool> visited;
        
        int total = 0;
        int currentSum = 0;
        checkRec(root, true, currentSum, sum, total, visited);
        return total;
    }
};

#endif /* PathSumIII_h */
