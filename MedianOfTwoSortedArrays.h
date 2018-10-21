//
//  MedianOfTwoSortedArrays.h
//  
//
//  https://leetcode.com/problems/median-of-two-sorted-arrays/description/
//

#ifndef MedianOfTwoSortedArrays_h
#define MedianOfTwoSortedArrays_h

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        
        while (nums1.size() > 0 || nums2.size() > 0)
        {
            if (nums1.size() > 0 && nums2.size() > 0)
            {
                if (nums1[0] < nums2[0])
                {
                    nums.push_back(nums1[0]);
                    nums1.erase(nums1.begin());
                }
                else
                {
                    nums.push_back(nums2[0]);
                    nums2.erase(nums2.begin());
                }
            }
            else if (nums1.size() > 0 && nums2.size() == 0)
            {
                nums.push_back(nums1[0]);
                nums1.erase(nums1.begin());
            }
            else if (nums1.size() == 0 && nums2.size() > 0)
            {
                nums.push_back(nums2[0]);
                nums2.erase(nums2.begin());
            }
        }
        
        if (nums.size() % 2 == 1)
        {
            return nums[(nums.size() - 1) / 2];
        }
        else
        {
            return (double)((nums[nums.size() / 2 - 1] + nums[nums.size() / 2])) / 2;
        }
    }
};

#endif /* MedianOfTwoSortedArrays_h */
