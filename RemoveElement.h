//
//  RemoveElement.h
//  
//
//  https://leetcode.com/problems/remove-element/description/
//

#ifndef RemoveElement_h
#define RemoveElement_h

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] == val)
            {
                nums.erase(nums.begin() + i);
            }
        }
        return nums.size();
    }
};

#endif /* RemoveElement_h */
