//
//  ThreeSumClosest.h
//  
//
//  https://leetcode.com/problems/3sum-closest/description/
//

#ifndef ThreeSumClosest_h
#define ThreeSumClosest_h

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int closest = INT_MAX;
        int value = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if (abs(nums[i]+nums[j]+nums[k] - target) < closest)
                    {
                        closest = abs(nums[i]+nums[j]+nums[k] - target);
                        value = nums[i]+nums[j]+nums[k];
                        if (closest == 0)
                        {
                            return value;
                        }
                    }
                }
            }
        }
        
        return value;
    }
};

#endif /* ThreeSumClosest_h */
