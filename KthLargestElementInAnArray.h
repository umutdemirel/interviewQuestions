//
//  KthLargestElementInAnArray.h
//  
//
//  https://leetcode.com/problems/kth-largest-element-in-an-array/description/
//

#ifndef KthLargestElementInAnArray_h
#define KthLargestElementInAnArray_h

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

#endif /* KthLargestElementInAnArray_h */
