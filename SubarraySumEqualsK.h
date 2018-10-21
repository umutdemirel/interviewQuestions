//
//  SubarraySumEqualsK.h
//  
//
//  https://leetcode.com/problems/subarray-sum-equals-k/description/
//

#ifndef SubarraySumEqualsK_h
#define SubarraySumEqualsK_h

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int total = 0;
            for (int j = i; j < nums.size(); j++)
            {
                total += nums[j];
                if (total == k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

#endif /* SubarraySumEqualsK_h */
