//
//  NextPermutation.h
//  
//
//  https://leetcode.com/problems/next-permutation/description/
//

#ifndef NextPermutation_h
#define NextPermutation_h

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2)
        {
            return;
        }
        
        int endingIndex = 0;
        while (true)
        {
            bool found = false;
            for (int i = nums.size() - 1; i >= endingIndex + 1; i--)
            {
                if (nums[i] > nums[i - 1])
                {
                    int target = nums[i - 1];
                    int targetIndex = 0;
                    int minDiff = INT_MAX;
                    int minValue = 0;
                    for (int j = i; j < nums.size(); j++)
                    {
                        if (nums[j] - target > 0 && nums[j] - target < minDiff)
                        {
                            minDiff = nums[j] - target;
                            targetIndex = j;
                            minValue = nums[j];
                        }
                    }
                    
                    int temp = target;
                    nums[i - 1] = minValue;
                    nums[targetIndex] = target;
                    endingIndex = i;
                    found = true;
                    break;
                }
            }
            sort(nums.begin() + endingIndex, nums.end());
            break;
        }
        
    }
};

#endif /* NextPermutation_h */
