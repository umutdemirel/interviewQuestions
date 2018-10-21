//
//  MaximumSubarray.h
//  
//
//  https://leetcode.com/problems/maximum-subarray/description/
//

#ifndef MaximumSubarray_h
#define MaximumSubarray_h

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentMax = INT_MIN;
        int maxNegative = 0;
        
        bool positiveFound = false;
        int tempPositives = 0;
        int tempNegatives = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0 && currentMax < nums[i])
            {
                currentMax = nums[i];
            }
            if (nums[i] >= 0)
            {
                positiveFound = true;
                tempPositives += nums[i];
                if (tempPositives + tempNegatives > currentMax)
                {
                    currentMax = tempPositives + tempNegatives;
                }
            }
            if (!positiveFound && nums[i] < 0)
            {
            }
            if (positiveFound && nums[i] < 0)
            {
                tempNegatives += nums[i];
            }
            if (tempPositives + tempNegatives < 0)
            {
                positiveFound = false;
                tempPositives = 0;
                tempNegatives = 0;
            }
        }
        
        if (currentMax == INT_MIN)
        {
            return maxNegative;
        }
        return currentMax;
    }
};

#endif /* MaximumSubarray_h */
