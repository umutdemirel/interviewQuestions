//
//  VerifyPreorderSerializationOfABinaryTree.h
//  
//
//  https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/
//

#ifndef VerifyPreorderSerializationOfABinaryTree_h
#define VerifyPreorderSerializationOfABinaryTree_h

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int numOfNulls = 1;
        bool numberStarted = false;
        bool treeFinished = false;
        for (int i = 0; i < preorder.size(); i++) {
            if (preorder[i] == '#') {
                numOfNulls--;
                if (numOfNulls <= 0) {
                    if (treeFinished == false) {
                        treeFinished = true;
                    } else {
                        return false;
                    }
                }
            } else if (preorder[i] == ',') {
                if (numberStarted) {
                    numberStarted = false;
                    numOfNulls++;
                }
            } else {
                numberStarted = true;
            }
        }
        if (numberStarted) {
            numOfNulls++;
        }
        
        if (numOfNulls == 0) {
            return true;
        } else {
            return false;
        }
    }
};

#endif /* VerifyPreorderSerializationOfABinaryTree_h */
