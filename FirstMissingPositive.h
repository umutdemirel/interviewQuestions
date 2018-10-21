//
//  FirstMissingPositive.h
//  
//
//  https://leetcode.com/problems/first-missing-positive/description/
//

#ifndef FirstMissingPositive_h
#define FirstMissingPositive_h

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector <bool> dict(100000, false);
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                dict[nums[i]] = true;
            }
        }
        
        for (int i = 1; i < dict.size(); i++)
        {
            if (dict[i] == false)
            {
                return i;
            }
        }
    }
};

#endif /* FirstMissingPositive_h */
