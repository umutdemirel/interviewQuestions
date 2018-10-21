//
//  MergeSortedArray.h
//  
//
//  https://leetcode.com/problems/merge-sorted-array/description/
//

#ifndef MergeSortedArray_h
#define MergeSortedArray_h

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int iterator0 = nums1.size() - 1;
        int iterator1 = m - 1;
        int iterator2 = n - 1;
        
        while (iterator2 >= 0) {
            if (iterator1 >= 0) {
                if (nums2[iterator2] >= nums1[iterator1]) {
                    nums1[iterator0] = nums2[iterator2];
                    iterator0--;
                    iterator2--;
                } else if (nums1[iterator1] > nums2[iterator2]) {
                    nums1[iterator0] = nums1[iterator1];
                    nums1[iterator1] = 0;
                    iterator1--;
                    iterator0--;
                }
            } else {
                nums1[iterator0] = nums2[iterator2];
                iterator0--;
                iterator2--;
            }
        }
    }
};

#endif /* MergeSortedArray_h */
