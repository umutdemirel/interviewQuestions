//
//  TargetSum.h
//  
//
//  https://leetcode.com/problems/target-sum/description/
//

#ifndef TargetSum_h
#define TargetSum_h

class Solution {
public:
    void recFind(vector<int>& nums, int S, int currentNum, int currentIndex, int& total) {
        if (currentIndex == nums.size()) {
            if (currentNum == S) {
                total++;
            }
            return;
        }
        
        recFind(nums, S, currentNum + nums[currentIndex], currentIndex + 1, total);
        recFind(nums, S, currentNum - nums[currentIndex], currentIndex + 1, total);
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        int total = 0;
        int currentIndex = 0;
        int currentNum = 0;
        
        recFind(nums, S, currentNum, currentIndex, total);
        
        return total;
    }
};

#endif /* TargetSum_h */
