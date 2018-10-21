//
//  MajorityElement.h
//  
//
//  https://leetcode.com/problems/majority-element/description/
//

#ifndef MajorityElement_h
#define MajorityElement_h

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++) {
            if (hashMap.find(nums[i]) == hashMap.end()) {
                hashMap[nums[i]] = 1;
            } else {
                hashMap[nums[i]]++;
                if (hashMap[nums[i]] > nums.size() / 2) {
                    return nums[i];
                }
            }
        }
    }
};

#endif /* MajorityElement_h */
