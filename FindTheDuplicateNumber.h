//
//  FindTheDuplicateNumber.h
//  
//
//  https://leetcode.com/problems/find-the-duplicate-number/description/
//

#ifndef FindTheDuplicateNumber_h
#define FindTheDuplicateNumber_h

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        int head = 0;
        while(head != slow) {
            slow = nums[slow];
            head = nums[head];
        }
        return slow;
    }
};

#endif /* FindTheDuplicateNumber_h */
