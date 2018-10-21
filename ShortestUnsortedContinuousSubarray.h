//
//  ShortestUnsortedContinuousSubarray.h
//  
//
//  https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
//

#ifndef ShortestUnsortedContinuousSubarray_h
#define ShortestUnsortedContinuousSubarray_h

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector <int> newNums{nums};
        sort(newNums.begin(), newNums.end());
        
        int changeFirst = -1;
        int changeLast = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != newNums[i]) {
                if (changeFirst == -1) {
                    changeFirst = i;
                }
                changeLast = i;
            }
        }
        
        return changeFirst == -1 ? 0 : changeLast - changeFirst + 1;
    }
};

#endif /* ShortestUnsortedContinuousSubarray_h */
