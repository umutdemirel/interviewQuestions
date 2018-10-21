//
//  RemoveDuplicatesFromSortedArray.h
//  
//
//  https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
//

#ifndef RemoveDuplicatesFromSortedArray_h
#define RemoveDuplicatesFromSortedArray_h

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            if (i < nums.size() - 1)
            {
                if (nums[i] == nums[i+1])
                {
                    nums.erase(nums.begin() + i);
                    i--;
                }
            }
        }
        return nums.size();
    }
};

#endif /* RemoveDuplicatesFromSortedArray_h */
