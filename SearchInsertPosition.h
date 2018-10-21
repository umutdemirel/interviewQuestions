//
//  SearchInsertPosition.h
//  
//
//  https://leetcode.com/problems/search-insert-position/description/
//

#ifndef SearchInsertPosition_h
#define SearchInsertPosition_h

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int i = 0;
        for (; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                return i;
            }
            else
            {
                if (target < nums[i])
                {
                    return i;
                }
            }
        }
        return i;
    }
};

#endif /* SearchInsertPosition_h */
