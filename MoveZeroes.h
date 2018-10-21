//
//  MoveZeroes.h
//  
//
//  https://leetcode.com/problems/move-zeroes/description/
//

#ifndef MoveZeroes_h
#define MoveZeroes_h

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        queue<int> indexQueue;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                indexQueue.push(i);
            } else {
                if (!indexQueue.empty()) {
                    int tempIndex = indexQueue.front();
                    indexQueue.pop();
                    nums[tempIndex] = nums[i];
                    nums[i] = 0;
                    i--;
                }
            }
        }
    }
};

#endif /* MoveZeroes_h */
